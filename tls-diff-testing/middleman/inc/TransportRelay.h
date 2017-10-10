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

#ifndef __TransportRelay_H__
#define __TransportRelay_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <vector>
#include <string>

using std::vector;
using std::string;

class TCPSocket;
class TCPServerSocket;
class TCPClientSocket;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class TransportRelay {

private:

	TCPServerSocket&	serverSocket_;
	TCPClientSocket&	outSocket_;
	TCPSocket*			inSocket_;

	uint8_t* buffer_;
	int bufferLen_;

	int logLevel_;
	string logPrefix_;


	void log(int minLevel, const string& msg);

	void bufferToVector(uint8_t* buffer, size_t bufferLen, vector<uint8_t>& data);


public:

	TransportRelay(int inPort, const string& destAddr, int destPort);

	void setLogPrefix(string prefix);
	void setLogLevel(int logLevel);
	int getLogLevel() const;

	bool process();
	bool close();

	ssize_t injectToServer(vector<uint8_t>& data);
	ssize_t injectToClient(vector<uint8_t>& data);

	virtual bool interceptToServer(vector<uint8_t>& data);
	virtual bool interceptToClient(vector<uint8_t>& data);

	virtual ~TransportRelay();

};

#endif
