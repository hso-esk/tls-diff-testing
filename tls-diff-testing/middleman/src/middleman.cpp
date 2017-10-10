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
#include "errno.h"

#include "VectorBuffer.h"
#include "BufferStreamReader.h"

#include "TransportRelay.h"
#include "Socket.h"
#include "TCPClientSocket.h"
#include "TCPServerSocket.h"

#include "../../tls-definitions.h"

using std::cout;
using std::endl;


class MyRelay : public TransportRelay {

private:

	std::ofstream* ofs;


public:

	TVector_MainType streamToServer;
	TVector_MainType streamToClient;


	MyRelay(int inPort, const string& destAddr, int destPort)
		: TransportRelay(inPort, destAddr, destPort) {

		ofs = 0;
	}

	virtual bool interceptToServer(vector<uint8_t>& data) {

		VectorBuffer buf;
		buf.appendBytes(&(data.at(0)), data.size());

		log(buf, "@C>S");

		BC from = streamToServer.getLength();

		BufferStreamReader reader(buf);
		streamToServer.dissector().dissect(reader);

		DataUnit::PrintOptions po;
		po.from = from;
		streamToServer.print(po);

		return true;
	}

	virtual bool interceptToClient(vector<uint8_t>& data) {

		bool keepConnection = true;

		VectorBuffer buf;
		buf.appendBytes(&(data.at(0)), data.size());

		log(buf, "@S>C");

		BC from = streamToClient.getLength();

		BufferStreamReader reader(buf);
		streamToClient.dissector().dissect(reader);

		/* check if server sent application data */
		if (streamToClient.getChildTail()->getChildByName("type")->propGet<int>(".value") == 3) {
			keepConnection = false;
		}

		DataUnit::PrintOptions po;
		po.from = from;
		streamToClient.print(po);

		return keepConnection;
	}

	void openLogFile(const string& filename) {

		ofs = 0;
		if (filename.length() > 0) {
			/* open the file to write data to */
			ofs = new std::ofstream(filename.c_str(), std::ofstream::out);
		}
	}

	void log(const Buffer& buffer, const string& prefix) {

		if (ofs != 0) {
			*ofs << prefix << endl;
			*ofs << "# " << buffer.getLength().toString() << " byte(s)" << endl;
			*ofs << buffer.toRawString() << endl;
		}
	}

	void closeLogFile() {

		if (ofs != 0) {
			ofs->close();
			ofs = 0;
		}
	}

};


int stringToPort(std::string strPort) {

	std::stringstream inPortParser(strPort);
	int port = 0;
	if (!(inPortParser >> port) || port < 0 || port > 0xFFFF) {
		port = -1;
	}
	return port;
}


int main(int argc , char *argv[]) {

	if (argc < 3) {
		puts("mitm: A simple Man-In-The-Middle relay station\n");
		puts("Usage: ./mitm IN-PORT DEST:DESTPORT [OPTIONS]\n");
		exit(0);
	}

	std::string strInPort = argv[1];
	std::string strDest = argv[2];

	int inPort = -1;
	int destPort = -1;
	std::string destAddr;

	// parse input port
	inPort = stringToPort(strInPort);
	if (inPort < 0) {
		puts("ERROR: Invalid input port. Stopping!");
		exit(1);
	}

	// parse destination host and port
	size_t colonPos = strDest.find(':');
	if (colonPos != std::string::npos) {
		destAddr = strDest.substr(0, colonPos);
		std::string portPart = strDest.substr(colonPos + 1);

		struct hostent* hp = gethostbyname(destAddr.c_str());
		if (hp && hp->h_addr_list[0] != NULL) {
			destAddr = inet_ntoa(*(struct in_addr*)(hp->h_addr_list[0]));
		} else {
			puts("ERROR: Failed to resolve host name. Stopping!");
			exit(1);
		}

		destPort = stringToPort(portPart);
		if (destPort < 0) {
			puts("ERROR: Invalid destination port. Stopping!");
			exit(1);
		}
	} else {
		puts("ERROR: Invalid destination. Stopping!");
		exit(1);
	}


	//bool printHexDump = false;
	std::string filename;

	int n = 3;
	while (n < argc && argv[n] != 0) {
		if (strcmp(argv[n], "-f") == 0) {
			n++;
			if (n < argc) {
				filename = argv[n];
			} else {
				puts("ERROR: Missing traffic filename. Stopping!");
				exit(1);
			}
		} else if (strcmp(argv[n], "-h") == 0) {
			//printHexDump = true;
		}
		n++;
	}

	MyRelay relay(inPort, destAddr, destPort);

	printf("INFO: localhost:%u ---> %s:%u\n", inPort, destAddr.c_str(), destPort);
	if (filename.length() > 0) {
		printf("INFO: Logging traffic to file '%s'\n", filename.c_str());
		relay.openLogFile(filename);
	}

	relay.setLogLevel(10);
	relay.setLogPrefix("[RELAY] ");

	while (relay.process());

	puts("END");

	relay.closeLogFile();

	return EXIT_SUCCESS;
}
