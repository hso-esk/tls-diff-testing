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

#include "errno.h"
#include <fcntl.h>
#include <stdexcept>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "BufferReader.h"
#include "BufferWriter.h"
#include "String_.h"
#include "UDPSocket.h"


/*
 * ___________________________________________________________________________
 */
UDPSocket::UDPSocket() {

	if (!this->create_()) {
		throw std::runtime_error(
				"TCPSocket(...): Could not create UDP socket.");
	}
}


/*
 * ___________________________________________________________________________
 */
UDPSocket::UDPSocket(int socket) : Socket(socket) {
}


/*
 * ___________________________________________________________________________
 */
bool UDPSocket::create_() {

	if (this->isValid()) {
		return false;
	}

	int socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (socket < 0) {
		return false;
	}

	int on = 1;
	if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR,
			(const char*)&on, sizeof(on)) == -1) {
		return false;
	}

	return this->setSocketFd_(socket);
}


/*
 * ___________________________________________________________________________
 */
ssize_t UDPSocket::send_(const uint8_t* const data, size_t len) {

	if (!this->hasRemoteAddress_()) {
		return -1;
	}

	int status = sendto(this->getSocketFd_(), data, len, 0,
			(struct sockaddr*)this->remoteAddress_(),
			this->remoteAddressSize_());

	return status;
}


/*
 * ___________________________________________________________________________
 */
ssize_t UDPSocket::recv_(uint8_t* const data, size_t maxLen) {

	return -1;
}


/*
 * ___________________________________________________________________________
 */
UDPSocket::~UDPSocket() {
}
