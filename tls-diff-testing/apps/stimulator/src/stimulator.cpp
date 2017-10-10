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

#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>
#include <deque>

#include "DataUnit.h"
#include "VectorBuffer.h"
#include "String_.h"
#include "../../../tls-definitions.h"
#include "TCPBatchClientSocket.h"

using namespace std;


// TODO: Add description
typedef struct {

    // TODO: Add description
    int slotId;

    // TODO: Add description
    string origin;

    // TODO: Add description
    TCPBatchClientSocket* socket;

    // TODO: Add description
    struct timeval tTimeout;

} Transaction_t;

// TODO: Add description
typedef struct {

    // TODO: Add description
    vector<string> servers;

    // TODO: Add description
    struct timeval tAvailable;

} Slot_t;

// TODO: Add description
void usage();

// TODO: Add description
void dissectAnswer(bool connected, const BufferReader& buffer,
        string& answer, int& answerCode, bool useColor, int reductionLevel);

// TODO: Add description
bool stimulate(const VectorBuffer& stimulus, const string& origin);

// TODO: Add description
void obtain(bool useColor, int reductionLevel);

// TODO: Add description
size_t iTransaction = 0;

// TODO: Add description
deque<Transaction_t> pending;

// TODO: Add description
vector<Slot_t> slots;


// TODO: Add description
int msTimeoutData = 100;

// TODO: Add description
int msBlockAfterUse = 250;

// TODO: Add description
int msBlockAfterFailure = 2000;


/*
 * ___________________________________________________________________________
 */
void usage() {
    cout << "./stimulator [OPTIONS] INPUT1 [INPUT2 ...]" << endl;
    cout << "-s<num>         The number of slots" << endl;
    cout << "-S<num>         ..." << endl;
    cout << "-o<num>         ..." << endl;
    cout << "-l<num>         ..." << endl;
    cout << "-L<num>         ..." << endl;
    cout << "-h<name>        ..." << endl;
    cout << "-c              ..." << endl;
    cout << "-q              ..." << endl;
    cout << "-r<num>         ..." << endl;
    cout << "-T<num>         ..." << endl;
}


/*
 * ___________________________________________________________________________
 */
int main(int argc , char *argv[]) {

    // TODO: Add description
    size_t nSlots = 1;

    // TODO: Add description
    size_t nServer = 1;

    // TODO: Add description
    int portOffset = 10000;

    // TODO: Add description
    int portStep = 100;

    // TODO: Add description
    int nLimitPerFile = -1;
    int nLimitTotal = -1;

    // TODO: Add description
    string hostname = "localhost";

    // Use colored ourput?
    bool useColor = false;

    // Just print parameters and exit?
    bool earlyExit = false;

    // Response reduction level [1, 2, 3]
    int reductionLevel = 3;

    int iArg = 1;

    while (iArg < argc) {
        string arg(argv[iArg]);
        if (arg.find("-s") == 0) {
            nSlots = atoi(arg.substr(2).c_str());
            iArg++;
        } else if (arg.find("-S") == 0) {
            nServer = atoi(arg.substr(2).c_str());
            iArg++;
        } else if (arg.find("-o") == 0) {
            portOffset = atoi(arg.substr(2).c_str());
            iArg++;
        } else if (arg.find("-l") == 0) {
            nLimitPerFile = atoi(arg.substr(2).c_str());
            iArg++;
        } else if (arg.find("-L") == 0) {
            nLimitTotal = atoi(arg.substr(2).c_str());
            iArg++;
        } else if (arg.find("-h") == 0) {
            hostname = arg.substr(2).c_str();
            iArg++;
        } else if (arg.find("-c") == 0) {
            useColor = true;
            iArg++;
        } else if (arg.find("-q") == 0) {
            earlyExit = true;
            iArg++;
        } else if (arg.find("-r") == 0) {
            reductionLevel = atoi(arg.substr(2).c_str());
            iArg++;
        } else if (arg.find("-T") == 0) {
            msTimeoutData = atoi(arg.substr(2).c_str());
            iArg++;
        } else if (arg.find("-") == 0) {
            cout << "Unknown option '" << arg << "'" << endl;
            usage();
            return 0;
        } else {
            break;
        }
    }

    slots.resize(nSlots);
    for (size_t iSlot = 0; iSlot < nSlots; iSlot++) {
        Slot_t& slot = slots.at(iSlot);
        gettimeofday(&slot.tAvailable, NULL);

        if (earlyExit) {
            cout << "Slot " << iSlot << endl;
        }

        for (size_t iServer = 0; iServer < nServer; iServer++) {
            int port = portOffset + iSlot * portStep + iServer;

            string server = String::format("%s:%i", hostname.c_str(), port);
            slot.servers.push_back(server);

            if (earlyExit) {
                cout << "-> " << server << endl;
            }
        }
    }

    if (earlyExit) {
        return 0;
    }
        
    string origin;
    VectorBuffer stimulus;

    int iArgOffset = iArg;

    for (; (iArg < argc) && (nLimitTotal != 0); iArg++) {

        // read input
	    String input(argv[iArg]);

	    if (input.removeLeadingText("0x")) {

            /* >>> single stimulus >>> */

            stimulus.clear();
		    stimulus.appendFromString(input);
            origin = String::format("#%08i", iArg + 1 - iArgOffset);

            /* stimulation */
            while (!stimulate(stimulus, origin)) {
                obtain(useColor, reductionLevel);
            }
            obtain(useColor, reductionLevel);

            if (nLimitTotal > 0) {
                nLimitTotal--;
            }

	    } else {

            /* >>> stimuli file >>> */

            string inputLine;
            ifstream file(input.c_str());
            size_t iLine = 1;

            if (!file.is_open()) {
                continue;
            }

            while ((nLimitPerFile < 0 || (int)iLine <= nLimitPerFile)
                    && (nLimitTotal != 0)
                    && std::getline(file, inputLine)) {

                size_t pos = inputLine.find_first_of(":");
                if (pos != string::npos) {
                    inputLine.erase(pos);
                }
                
                stimulus.clear();
    		    stimulus.appendFromHexString(inputLine);
                origin = String::format("%s#%08i", input.c_str(), iLine);

                /* stimulation */
                while (!stimulate(stimulus, origin)) {
                    obtain(useColor, reductionLevel);
                }
                obtain(useColor, reductionLevel);

                if (nLimitTotal > 0) {
                    nLimitTotal--;
                }

                iLine++;
            }
	    }

        while (pending.size() > 0) {
            obtain(useColor, reductionLevel);
        }
    }
    
	return 0;
}


/*
 * ___________________________________________________________________________
 */
bool stimulate(const VectorBuffer& stimulus, const string& origin) {

    /* find available slot */
    vector<int> options;
    struct timeval tNow;
    gettimeofday(&tNow, NULL);
    for (size_t iSlot = 0; iSlot < slots.size(); iSlot++) {
        Slot_t& slot = slots.at(iSlot);
        if (timerisset(&slot.tAvailable)
                && timercmp(&slot.tAvailable, &tNow, <)) {
            options.push_back(iSlot);
        }
    }
    if (options.size() == 0) {
        return false;
    }

    size_t slotId = 0;
    struct timeval tMin;
    for (size_t i = 0; i < options.size(); i++) {
        if (i == 0 || timercmp(&tMin, &slots[options[i]].tAvailable, >)) {
            tMin = slots[options[i]].tAvailable;
            slotId = options[i];
        }
    }
   
    //cout << "Stimulate slot: " << slotId << " ";

    /* Setup batch socket */
    TCPBatchClientSocket* socket = new TCPBatchClientSocket();
    for (vector<string>::const_iterator it = slots.at(slotId).servers.begin();
		    it != slots.at(slotId).servers.end(); ++it) {
        socket->addServer(*it);
    }

    bool success = false;

    /* Connect batch socket */
    if (socket->connect() == socket->getNServer()) {

        timerclear(&slots.at(slotId).tAvailable);

        socket->setNonBlocking(true);

        *socket << stimulus;        

        Transaction_t trans;
        trans.slotId = slotId;
        trans.origin = origin;
        trans.socket = socket;

        struct timeval t50us;
        timerclear(&t50us);
        t50us.tv_usec = msTimeoutData * 1000;

        gettimeofday(&tNow, NULL);
        gettimeofday(&trans.tTimeout, NULL);
        timeradd(&tNow, &t50us, &trans.tTimeout);

        pending.push_back(trans);

        success = true;

        //cout << "-> ok" << endl;

    } else {

        /* >>> failed to connect >>> */
        /*  => block this slot for one second  */

        struct timeval tBlock;
        timerclear(&tBlock);
        tBlock.tv_usec = msBlockAfterFailure * 1000;
        gettimeofday(&tNow, NULL);
        timeradd(&tNow, &tBlock, &slots.at(slotId).tAvailable);

        //cout << "-> failed" << endl;
    }

    return success;
}


/*
 * ___________________________________________________________________________
 */
void obtain(bool useColor, int reductionLevel) {

    if (pending.size() == 0) {
        return;
    }    

    Transaction_t& trans = pending.front();
    TCPBatchClientSocket* socket = trans.socket;

    bool ready = true;
    for (size_t i = 0; i < socket->getNServer(); ++i) {
        if ((*socket)[i].getAvailableData() == 0) {
            ready = false;
        }
    }

    struct timeval tNow;
    if (!ready) {
        gettimeofday(&tNow, NULL);
        if (timercmp(&trans.tTimeout, &tNow, >)) {
            return;
        }
    }

    //cout << "Obtain " << trans.slotId << endl;

    string reply = trans.origin;
    reply.append(":");

    VectorBuffer bufReply;

    for (size_t i = 0; i < socket->getNServer(); ++i) {

        int answerCode = 0;
        String answer;

        bufReply.clear();
        (*socket)[i] >> bufReply;

        bool connected = (*socket)[i].isConnected();
        dissectAnswer(connected, bufReply, answer,
                answerCode, useColor,reductionLevel);

        reply.append(answer);
        if ((i + 1) < socket->getNServer()) {
    	    reply.append(";");
        }
    }

    time_t rawtime;
    struct tm* timeinfo;
    char timebuf[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timebuf, 80, "%Y%m%d-%H%M%S", timeinfo);

    reply.append(String::format(":SLOT=%i;T=%s", trans.slotId, timebuf));

    cout << reply << endl;

    /* make slot availabel in 1s */
    struct timeval tBlock;
    timerclear(&tBlock);
    tBlock.tv_usec = msBlockAfterUse * 1000;
    gettimeofday(&tNow, NULL);
    timeradd(&tNow, &tBlock, &slots.at(trans.slotId).tAvailable);

    delete socket;
    pending.pop_front();
}


/*
 * ___________________________________________________________________________
 */
void dissectAnswer(bool connected, const BufferReader& buffer,
        string& answer, int& answerCode, bool useColor, int reductionLevel) {

    DataUnit* du;

	TVector_MainType inRec;
	inRec.dissector().dissectFromBuffer(buffer);

	if (inRec.getLength() > 0) {
		string type = inRec[0]->propGet<string>("~0/.name");
		if (type == "alert") {

			answerCode = -1;

            if (reductionLevel > 1) {
                if (!useColor) {
        			answer = "AL";
                } else {
        			answer = "\033[1;31mAL\033[0m";
                }
                /* Alert type */
                du = inRec[0]->getByPath("alert/description");
                if (du != 0) {
		            answer.append("/");
		            answer.append(du->propGet<string>(".value"));    
                }
            } else {
                if (!useColor) {
        			answer = "A";
                } else {
        			answer = "\033[1;31mA\033[0m";
                }
            }

            if (reductionLevel > 2) {
                /* Record version */
                du = inRec[0]->getByPath("version");
                if (du != 0) {
			        answer.append("/V");
			        answer.append(du->toHexString());    
                }
            }

		} else if (type == "handshake") {

			answerCode = 1;

            if (reductionLevel > 1) {
                if (!useColor) {
			        answer = "HS";
                } else {
			        answer = "\033[1;32mHS\033[0m";
                }
                /* Handshake message type */
                du = inRec[0]->getByPath("hsMsg/type");
                if (du != 0) {
	                answer.append("/");
	                answer.append(du->propGet<string>(".value"));    
                }
            } else {
                if (!useColor) {
			        answer = "H";
                } else {
			        answer = "\033[1;32mH\033[0m";
                }
            }

            if (reductionLevel > 2) {
                /* Record version */
                du = inRec[0]->getByPath("version");
                if (du != 0) {
			        answer.append("/V");
			        answer.append(du->toHexString());    
                }

                /* ClientHello version */
                du = inRec[0]->getByPath("hsMsg/serverHello/version");
                if (du != 0) {
			        answer.append("/v");
			        answer.append(du->toHexString());    
                }
            }

		} else {
            answer = "?";
        }
	} else /*if (connected)*/ {
		answerCode = -1;
        if (!useColor) {
			answer = "E";
        } else {
    		answer = "\033[1;33mE\033[0m";
        }
	}

    if (reductionLevel == 0) {
        if (answerCode < 0) {
            if (!useColor) {
    			answer = "0";
            } else {
    			answer = "\033[1;31m0\033[0m";
            }
        } else {
            if (!useColor) {
    			answer = "1";
            } else {
    			answer = "\033[1;32m1\033[0m";
            }
        }
    }
}



