/*
 *  Copyright (C) 2017
 *  Andreas Walz [andreas.walz@hs-offenburg.de]
 *  Offenburg University of Applied Sciences
 *  Institute of Reliable Embedded Systems and Communications Electronics (ivESK)
 *  [https://ivesk.hs-offenburg.de/]
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <sstream>
#include <netdb.h>
#include <map>
#include <utility>
#include <vector>
#include <cmath>
#include "errno.h"
#include <time.h>

#include "DataUnit.h"
#include "EnumerationField.h"
#include "VectorBuffer.h"
#include "TCPClientSocket.h"
#include "TCPServerSocket.h"
#include "UDPClientSocket.h"
#include "BufferStreamReader.h"
#include "PropertyNode.h"
#include "FileStreamReader.h"
#include "DecisionReader.h"
#include "DataUnitFilter.h"
#include "DataUnitCursor.h"
#include "DataUnitVisitor.h"
#include "FuzzOperator.h"
#include "DataUnitOperator.h"
#include "VoidField.h"
#include "../../tls-definitions.h"
#include "SHA256.h"
#include "TCPBatchClientSocket.h"

using namespace std;


/* TODO: Add description */
int test_servers(string inputRandomFile, string outputFile, size_t N, size_t nMaxOp, const vector<bool>& opEnable);

/* TODO: Add description */
void writeToFile(const string& filename, const string& text, bool append = false);


/*
 * ___________________________________________________________________________
 */
int main(int argc , char *argv[]) {

    /* Maximum number of operator applications */
    size_t nMaxOp = -1;

    /* Operator filter */
    vector<bool> opEnable;

    int iArg = 1;

    while (iArg < argc) {
        string arg(argv[iArg]);
        if (arg.find("-n") == 0) {
            nMaxOp = atoi(arg.substr(2).c_str());
            iArg++;
        } else if (arg.find("-f") == 0) {
            arg.erase(0, 2);
            for (size_t ic = 0; ic < arg.length(); ic++) {
                opEnable.push_back(arg[ic] == '1');
            }
            iArg++;
        } else {
            break;
        }
    }

    if ((argc - iArg) != 3) {
        cout << "ERROR: Wrong number of arguments" << endl;
        cout << "./generate [OPTIONS] <RANDOM-INPUT-FILE> <OUTPUT-FILE> <N>" << endl;
        return 1;
    }

    string randomInputFile(argv[iArg++]);

    string outputFile(argv[iArg++]);

    size_t N = atoi(argv[iArg++]);

    return test_servers(randomInputFile, outputFile, N, nMaxOp, opEnable);
}


/*
 * ___________________________________________________________________________
 */
class GlobalFilter : public DataUnitFilter {

public:

	bool apply(const DataUnit& dataUnit) const {

		return dataUnit.getDistanceToRoot() > 1 && /*dataUnit.getLength() > 0 &&*/ dataUnit.getName() != "CipherSuite";
	}

};


/*
 * ___________________________________________________________________________
 */
class MyFilter3 : public DataUnitFilter {

public:

	bool apply(const DataUnit& dataUnit) const {

		return (dataUnit.hasParent() && dataUnit.getParent()->containsType(VectorDataUnit::typeDescriptor())) ||
				!dataUnit.hasNext();
	}

};



/*
 * ___________________________________________________________________________
 */
class VectorElementFilter : public DataUnitFilter {

public:

	bool apply(const DataUnit& dataUnit) const {

		return dataUnit.hasParent() && dataUnit.getParent()->containsType(VectorDataUnit::typeDescriptor());
	}

};


/*
 * ___________________________________________________________________________
 */
class DynamicLengthFilter : public DataUnitFilter {

public:

	bool apply(const DataUnit& dataUnit) const {

		int dynlen = 0;
		dataUnit.propGet<int>("_dynlen", dynlen);
		return dynlen > 0;
	}

};


/*
 * ___________________________________________________________________________
 */
class GeneratingFuzzOpFilter : public DataUnitFilter {

public:

	bool apply(const DataUnit& dataUnit) const {

        bool accept = false;

        if (dataUnit.isOfType(TStruct_Extension::typeDescriptor())) {
            accept = true;
        } else if (dataUnit.isOfType(TStruct_ClientHello_extensions::typeDescriptor())) {
            accept = true;
        } else if (dataUnit.isOfType(TStruct_ClientHello_cipher_suites::typeDescriptor())) {
            accept = true;
        }   

        return accept;
	}

};


/*
 * ___________________________________________________________________________
 */
size_t applyOperators(DecisionReader& decisionReader, DataUnit& operand, string& summary, int nMaxOp, const vector<bool>& opEnable) {

	size_t nOp = 0;

	VoidingOperator voidOp;
	DuplicatingOperator duplOp;
	DeletingOperator delOp;
	FuzzIntOperator fuzzIntOp(decisionReader);
	TruncationFuzzOperator truncFuzzOp(decisionReader);
	FuzzDataOperator fuzzDataOp(decisionReader, true);
	AppendingFuzzOperator appFuzzOp(decisionReader);
	GeneratingFuzzOperator genFuzzOp(decisionReader);

	DynamicLengthFilter dynLenFilter;
	VectorElementFilter vecItemFilter;
    GeneratingFuzzOpFilter genFuzzOpFilter;

	vector<DataUnitOperator*> operators;
	vector<DataUnitFilter*> filters;

    if (opEnable.size() <= 0 || opEnable[0]) {
	    operators.push_back(&voidOp);
	    filters.push_back(&dynLenFilter);
    }
    if (opEnable.size() <= 1 || opEnable[1]) {
	    operators.push_back(&duplOp);
	    filters.push_back(&vecItemFilter);
    }
    if (opEnable.size() <= 2 || opEnable[2]) {
	    operators.push_back(&delOp);
	    filters.push_back(&vecItemFilter);
    }
    if (opEnable.size() <= 3 || opEnable[3]) {
	    operators.push_back(&fuzzIntOp);
	    filters.push_back(0);
    }
    if (opEnable.size() <= 4 || opEnable[4]) {
	    operators.push_back(&truncFuzzOp);
	    filters.push_back(&dynLenFilter);
    }
    if (opEnable.size() <= 5 || opEnable[5]) {
	    operators.push_back(&fuzzDataOp);
	    filters.push_back(0);
    }
    if (opEnable.size() <= 6 || opEnable[6]) {
	    operators.push_back(&appFuzzOp);
	    filters.push_back(&dynLenFilter);
    }
    if (opEnable.size() <= 7 || opEnable[7]) {
	    operators.push_back(&genFuzzOp);
	    filters.push_back(&genFuzzOpFilter);
    }


	GlobalFilter globalFilter;


    do {

	    /* select a operator at random */
        if (operators.size() == 0) {
            cout << "No operators" << endl;
            break;
        }
	    size_t iOp = decisionReader.readUIntUniform(operators.size());
	    DataUnitOperator* op = operators[iOp];
	    DataUnitFilter* opFilter = filters[iOp];

	    /* select a data unit to operate on at random */
	    ConjunctionDataUnitFilter filter(globalFilter,
			    op->getApplicationFilter(), *opFilter);

	    String line;

	    DataUnitCursor cursor(operand);

	    size_t nDu = cursor.count(filter);
        if (nDu == 0) {
            continue;
        }

    	bool applyRecursive = false;

		size_t iDu = decisionReader.readUIntUniform(nDu);
		cursor.seekByIndex(iDu, filter);

		if (op->apply(cursor)) {

            /* path operator has been applied at */
		    String path = cursor.getCurrent().getPath();

            /* operator name */
			PropertyNode& opLog = op->getLastOperationLog();
			string opType = "unknown";
			opLog.propGet<string>("operator.type", opType);

		    line = String::format("%s@%s: ", opType.c_str(), path.c_str());

			bool repair = true;

			if (opType == "VoidingOperator") {

				line.append("voided");

			} else if (opType == "DuplicatingOperator") {

				line.append("duplicated");
				applyRecursive = true;

			} else if (opType == "DeletingOperator") {

				line.append("deleted");

			} else if (opType == "TruncationFuzzOperator") {

				line.appendFormat("truncated %s -> %s",
						opLog.propGet<string>("operand.length").c_str(),
						opLog.propGet<string>("operand.length.after").c_str());

			} else if (opType == "FuzzDataOperator") {

				repair = false;
				line.appendFormat("random content -> %s",
						opLog.propGet<string>("operand.length.after").c_str());

			} else if (opType == "FuzzIntOperator") {

				repair = false;
				line.appendFormat("%s --> %s",
						opLog.propGetDefault<string>("int.before", "##").c_str(),
						opLog.propGet<string>("int.after").c_str());

			} else if (opType == "AppendingFuzzOperator") {

				line.append("AppendingFuzzOperator");

			} else if (opType == "GeneratingFuzzOperator") {

				line.append("GeneratingFuzzOperator");
				applyRecursive = true;

			} else if (opType == "unknown") {

				line.append("unknown operator");

			}

			if (repair) {
				RepairingFuzzOperator repOp(decisionReader);
				repOp.apply(cursor);
				line.append(" ");
				line.append(repOp.getLastOperationLog().propGet<string>("operator.repairtrace"));
			}

			nOp += 1;
		    if (summary.length() > 0) {
			    summary.append("\n");
		    }
		    summary.append(line);

            if (decisionReader.readBoolUniform()
                    && cursor.valid()
                    && applyRecursive
                    && ((nMaxOp < 0) || (nOp < (size_t)nMaxOp))) {

	            nOp += applyOperators(decisionReader, cursor.getCurrent(),
                        summary, nMaxOp < 0 ? nMaxOp : nMaxOp - nOp, opEnable);
            }
		}

    } while (((nMaxOp < 0) || (nOp < (size_t)nMaxOp))
//            && (decisionReader.readUIntUniform(256) < 200));
            && decisionReader.readBoolUniform());

	return nOp;
}



int test_servers(string inputRandomFile, string outputFile, size_t N, size_t nMaxOp, const vector<bool>& opEnable) {

    cout << "Generating " << N << " inputs." << endl;

	/* load the ClientHello template */
	VectorBuffer outBuf;
	outBuf.appendFromString(
			"160301012c01000128030340c70e243001b96d8c63687738696432d3e6f949"
			"107aabad8450cdffd6a266e4000092c030c02cc028c024c014c00a00a3009f"
			"006b006a0039003800880087c032c02ec02ac026c00fc005009d003d003500"
			"84c02fc02bc027c023c013c00900a2009e0067004000330032009a00990045"
			"0044c031c02dc029c025c00ec004009c003c002f00960041c011c007c00cc0"
			"0200050004c012c00800160013c00dc003000a001500120009001400110008"
			"0006000300ff0100006d000b000403000102000a00340032000e000d001900"
			"0b000c00180009000a00160017000800060007001400150004000500120013"
			"000100020003000f0010001100230000000d0020001e060106020603050105"
			"020503040104020403030103020303020102020203000f000101");

	/* dissect and print original ClientHello */
	TVector_MainType printRec;
	printRec.dissector().dissectFromBuffer(outBuf);
	printRec.print();

	/* fuzzing infrastructure */
	FileStreamReader ctrlStream(inputRandomFile);
	DecisionReader selector(ctrlStream);


	String line;
	std::map<string, bool> hashMap;
    size_t nDuplicates = 0;

	for (size_t n = 0; n < N;) {

		TVector_MainType outRec;
		outRec.dissector().dissectFromBuffer(outBuf);

        size_t nOp = 0;
		String summary;
        VectorBuffer outBuf;

		if (n == 0) {

			summary.append("No change");

		} else {

            nOp = applyOperators(selector, outRec, summary, nMaxOp, opEnable);
			if (nOp == 0) {
				continue;
			}

            if (outRec[0] != 0) {
                /* make sure record length is correct */
                //outRec(0).repair(false);
            }
		}

        outRec.copyTo(outBuf);

		/* calculate message hash to skip cases that have already been used */
		VectorBuffer hash;
		SHA256 sha256;
		sha256.digest(outBuf, hash);
		string hashString = hash.toHexString();
		if (hashMap.count(hashString) > 0) {
            nDuplicates++;
			continue;
		}
		hashMap[hashString] = true;


        if (outputFile != "-") {

            time_t rawtime;
            struct tm* timeinfo;
            char timebuf[80];
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strftime(timebuf, 80, "%Y%m%d-%H%M%S", timeinfo);

		    String clientDataStr;
		    clientDataStr.append(outBuf.toHexString());
            clientDataStr.appendFormat(":ID=%u;nOp=%u;time=%s", n, nOp, timebuf);
		    writeToFile(outputFile, clientDataStr, true);
        }


		line = String::format("[%09u] ", n);
		size_t nLines = summary.countLines();
		line.appendRepeated("\n            ", nLines);
		line.appendColumn(summary);

		cout << line << endl;

        ++n;
	}

	cout << "Random stream used: ";
	selector.getAccumulator().print();

    cout << "Hash map size: " << hashMap.size() << endl;

    cout << "Number of rejected duplicates: " << nDuplicates << endl;

	return 0;
}


void writeToFile(const string& filename, const string& text, bool append) {

	ios_base::openmode mode = std::ofstream::out;
	if (append) {
		mode |= std::ios_base::app;
	}

	std::ofstream ofs(filename.data(),  mode);
	if (ofs.is_open()) {
		ofs << text << endl;
		ofs.close();
	}
}
