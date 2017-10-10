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

#include "TransportRelay.h"
#include "errno.h"
#include "String_.h"
#include "TCPServerSocket.h"
#include "TCPClientSocket.h"


/*
 * ___________________________________________________________________________
 */
TransportRelay::TransportRelay(
		int inPort, const string& destAddr,	int destPort) :
		serverSocket_(*(new TCPServerSocket(inPort))),
		outSocket_(*(new TCPClientSocket(destAddr, destPort))),
		inSocket_(0) {

	serverSocket_.setNonBlocking(true);
	outSocket_.setNonBlocking(true);
}


/*
 * ___________________________________________________________________________
 */
void TransportRelay::bufferToVector(
		uint8_t* buffer, size_t bufferLen, vector<uint8_t>& data) {

	for (size_t i = 0; i < bufferLen; i++) {
		data.push_back(buffer[i]);
	}
}


/*
 * ___________________________________________________________________________
 */
void TransportRelay::setLogPrefix(string prefix) {

	logPrefix_ = prefix;
}


/*
 * ___________________________________________________________________________
 */
void TransportRelay::setLogLevel(int logLevel) {

	logLevel_ = logLevel;
}


/*
 * ___________________________________________________________________________
 */
int TransportRelay::getLogLevel() const {

	return logLevel_;
}


/*
 * ___________________________________________________________________________
 */
void TransportRelay::log(int minLevel, const string& msg) {

	if (logLevel_ >= minLevel) {
		printf("%s%s\n", logPrefix_.c_str(), msg.c_str());
	}
}


/*
 * ___________________________________________________________________________
 */
bool TransportRelay::process() {

	bool requestClose = false;

	/* accept incoming connection */
	if (inSocket_ == 0) {
		inSocket_ = serverSocket_.accept();
		if (inSocket_ != 0 && inSocket_->isConnected()) {
			inSocket_->setNonBlocking(true);
			log(2, "Client ---> [CONNECT]");
		}
	}
	if (inSocket_ == 0 || !inSocket_->isConnected()) {
		return true;
	}

	/* establish outgoing connection */
	if (!outSocket_.isConnected()) {
		outSocket_.connect();
		if (outSocket_.isConnected()) {
			log(2, "[CONNECT] ---> Server");
		}
	}

	if (!outSocket_.isConnected()) {
		return true;
	}


	/*
	 * Client ---> Server
	 */
	vector<uint8_t> data;
	*inSocket_ >> data;
	if (data.size() > 0) {
		log(2, String::format(
				"Client ---> [%d bytes]    > Server", data.size()));
		if (!this->interceptToServer(data)) {
			requestClose = true;
		}
		outSocket_ << data;
	}


	/*
	 * Client <--- Server
	 */
	data.clear();
	outSocket_ >> data;
	if (data.size() > 0) {
		log(2, String::format(
				"Client <    [%d bytes] <--- Server", data.size()));
		if (!this->interceptToClient(data)) {
			requestClose = true;
		}
		*inSocket_ << data;
	}

	if (requestClose) {
		log(2, "Client <--- [CLOSE] ---> Server");
		outSocket_.disconnect();
		inSocket_->disconnect();
		return false;
	} else {
		if (!inSocket_->isConnected()) {
			log(2, "Client ---> [CLOSE] ---> Server");
			outSocket_.disconnect();
			return false;
		}
		if (!outSocket_.isConnected()) {
			log(2, "Client <--- [CLOSE] <--- Server");
			inSocket_->disconnect();
			return false;
		}
	}

	return true;
}


/*
 * ___________________________________________________________________________
 */
bool TransportRelay::close() {

	if (inSocket_ != 0) {
		inSocket_->close();
		delete inSocket_;
	}
	serverSocket_.close();
	outSocket_.close();

	return true;
}


/*
 * ___________________________________________________________________________
 */
ssize_t TransportRelay::injectToServer(vector<uint8_t>& data) {

	return -1;
}


/*
 * ___________________________________________________________________________
 */
ssize_t TransportRelay::injectToClient(vector<uint8_t>& data) {

	return -1;
}


/*
 * ___________________________________________________________________________
 */
bool TransportRelay::interceptToServer(vector<uint8_t>& data) {

	/* returning false would close the connection */
	return true;
}


/*
 * ___________________________________________________________________________
 */
bool TransportRelay::interceptToClient(vector<uint8_t>& data) {

	/* returning false would close the connection */
	return true;
}


/*
 * ___________________________________________________________________________
 */
TransportRelay::~TransportRelay() {

	this->close();
	delete &serverSocket_;
	delete &outSocket_;
}

