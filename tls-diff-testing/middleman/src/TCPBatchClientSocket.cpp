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

#include "TCPBatchClientSocket.h"
#include "BufferReader.h"


/*
 * ___________________________________________________________________________
 */
TCPBatchClientSocket::TCPBatchClientSocket() {


}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::addServer(const string& hostAndPort) {

	sockets_.push_back(new TCPClientSocket(hostAndPort));
	return true;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::addServer(const string& host, int port) {

	sockets_.push_back(new TCPClientSocket(host, port));
	return true;
}


/*
 * ___________________________________________________________________________
 */
size_t TCPBatchClientSocket::connect() {

	size_t n = 0;

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		if ((*it)->connect()) {
			++n;
		}
	}

	return n;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::disconnect() {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		(*it)->disconnect();
	}

	return true;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::close() {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		(*it)->close();
	}

	return true;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::allConnected() const {

    bool connected = (sockets_.size() > 0);

	for (socket_vector_type_t::const_iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		if (!(*it)->isConnected()) {
            connected = false;
        }
	}

	return connected;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::setNonBlocking(bool nonBlocking) {

	bool success = true;

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		if (!(*it)->setNonBlocking(nonBlocking)) {
			success = false;
		}
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
void TCPBatchClientSocket::setTimeout(size_t seconds) {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		(*it)->setTimeout(seconds);
	}
}


/*
 * ___________________________________________________________________________
 */
const TCPBatchClientSocket& TCPBatchClientSocket::operator<<(
		const BufferReader& reader) {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		if ((*it)->isConnected()) {
			*(*it) << reader;
		}
	}

	return *this;
}


/*
 * ___________________________________________________________________________
 */
TCPBatchClientSocket::~TCPBatchClientSocket() {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		delete *it;
	}
}

