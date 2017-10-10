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

#include "TCPServerSocket.h"
#include "String_.h"
#include "errno.h"
#include <fcntl.h>
#include <stdexcept>


/*
 * ___________________________________________________________________________
 */
TCPServerSocket::TCPServerSocket(int port) {

	port_ = port;

	if (!this->bind_(port)) {
		throw std::runtime_error(
				"TCPServerSocket(...): Could not bind to port.");
	}
	if (!this->listen_()) {
		throw std::runtime_error(
				"TCPServerSocket(...): Could not listen to socket.");
	}
}


/*
 * ___________________________________________________________________________
 */
bool TCPServerSocket::bind_(int port) {

	if (!this->isValid()) {
		return false;
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);

	int bind_return = ::bind(this->getSocketFd_(),
			(struct sockaddr*)&addr, sizeof(addr));

	return (bind_return != -1);
}


/*
 * ___________________________________________________________________________
 */
bool TCPServerSocket::listen_(int maxConnections) const {

	if (!this->isValid()) {
		return false;
	}

	int listen_return = ::listen(this->getSocketFd_(), maxConnections);

	return (listen_return != -1);
}


/*
 * ___________________________________________________________________________
 */
int TCPServerSocket::accept_() const {

	if (!this->isValid()) {
		return false;
	}

	sockaddr_in addr;
	socklen_t addr_length = (socklen_t)sizeof(addr);

	return ::accept(this->getSocketFd_(), (sockaddr*)&addr, &addr_length);
}


/*
 * ___________________________________________________________________________
 */
TCPSocket* TCPServerSocket::accept() {

	TCPSocket* srvSock = (TCPSocket*)0;

	int socket = accept_();
	if (socket > 0) {
		srvSock = new TCPSocket(socket);
	}

	return srvSock;
}


/*
 * ___________________________________________________________________________
 */
TCPServerSocket::~TCPServerSocket() {
}
