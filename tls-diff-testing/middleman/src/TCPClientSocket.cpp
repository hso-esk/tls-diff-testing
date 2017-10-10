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

#include "TCPClientSocket.h"
#include "String_.h"
#include "errno.h"
#include <fcntl.h>
#include <stdexcept>

using std::vector;
using std::string;


/*
 * ___________________________________________________________________________
 */
TCPClientSocket::TCPClientSocket(const string& hostAndPort) {

	if (!this->setRemoteAddress(hostAndPort)) {
		throw std::runtime_error(
				"TCPClientSocket(...): Failed to resolve host address");
	}
}


/*
 * ___________________________________________________________________________
 */
TCPClientSocket::TCPClientSocket(const string& host, int port) {

	if (!this->setRemoteAddress(host, port)) {
		throw std::runtime_error(
				"TCPClientSocket(...): Failed to resolve host address");
	}
}


/*
 * ___________________________________________________________________________
 */
bool TCPClientSocket::connect() {

	if (!this->isValid() && !this->create_()) {
		return false;
	}

	int status = ::connect(this->getSocketFd_(),
			(sockaddr*)this->remoteAddress_(), this->remoteAddressSize_());
	if (status == 0) {
		connected_ = true;
	}

	return this->isConnected();
}


/*
 * ___________________________________________________________________________
 */
TCPClientSocket::~TCPClientSocket() {
}
