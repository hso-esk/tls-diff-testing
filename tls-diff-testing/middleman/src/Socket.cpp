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
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sstream>
#include <netdb.h>
#include "BufferReader.h"
#include "BufferWriter.h"
#include "String_.h"
#include "Socket.h"

using std::string;
using std::stringstream;

#define BUFFER_SIZE 1024*16


/*
 * ___________________________________________________________________________
 */
Socket::Socket() : socket_(-1), bcIn_(0), bcOut_(0), hasRemoteAddr_(false) {

	memset((char*)&remoteAddr_, 0, sizeof(remoteAddr_));
}


/*
 * ___________________________________________________________________________
 */
Socket::Socket(int socket) : socket_(socket),
		bcIn_(0), bcOut_(0), hasRemoteAddr_(false) {

	memset((char*)&remoteAddr_, 0, sizeof(remoteAddr_));
}


/*
 * ___________________________________________________________________________
 */
bool Socket::setSocketFd_(int socket) {

	bool success = false;

	if (socket >= 0) {
		socket_ = socket;
		success = true;
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool Socket::close() {

	bool success = false;

	if (this->isValid() && ::close(socket_) == 0) {
		socket_ = -1;
		success = true;
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool Socket::setNonBlocking(bool nonBlocking) {

	bool success = false;

	int opts = fcntl(socket_, F_GETFL);
	if (opts >= 0) {
		if (nonBlocking) {
			opts = ( opts | O_NONBLOCK );
		} else {
			opts = ( opts & ~O_NONBLOCK );
		}
		if (fcntl(socket_, F_SETFL, opts) >= 0) {
			success = true;
		}
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool Socket::setRemoteAddress(const string& hostAndPort) {

	bool success = false;

	size_t colonPos = hostAndPort.find(':');
	if (colonPos != string::npos) {

		/* resolve host */
		string host(hostAndPort.substr(0, colonPos));
		struct hostent* hp = gethostbyname(host.c_str());
		if (hp && hp->h_addr_list[0] != NULL) {
			host = inet_ntoa(*(struct in_addr*)(hp->h_addr_list[0]));
			success = true;
		}

		/* parse port number */
		int port = 0;
		if (success) {
			stringstream inPortParser(hostAndPort.substr(colonPos + 1));
			success = (inPortParser >> port) && port >= 0 && port <= 0xFFFF;
		}

		/* set remote address using results from parsing */
		if (success) {
			success = this->setRemoteAddress(host, port);
		}
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool Socket::setRemoteAddress(const string& host, int port) {

	bool success = false;

	if (port >= 0 && port <= 0xFFFF) {
		sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);

		inet_pton(AF_INET, host.c_str(), &addr.sin_addr);
		if (errno != EAFNOSUPPORT) {
			remoteAddr_ = addr;
			hasRemoteAddr_ = true;
			success = true;
		}
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
void Socket::setTimeout(size_t seconds) {

	struct timeval tv;
	tv.tv_sec = seconds;
	tv.tv_usec = 0;
	setsockopt(socket_, SOL_SOCKET, SO_RCVTIMEO,
			(char*)&tv, sizeof(struct timeval));
}


/*
 * ___________________________________________________________________________
 */
int Socket::getAvailableData() const {

    int n = -1;
    ioctl(socket_, FIONREAD, &n);
    return n;
}


/*
 * ___________________________________________________________________________
 */
const Socket& Socket::operator<<(const BufferReader& reader) {

	uint8_t buf[BUFFER_SIZE];

	BC len = reader.copyTo(buf, sizeof(buf));

	ssize_t sent = send_(buf, len.byte());

	if (sent < 0 || (size_t)sent != len.byte()) {
		throw std::runtime_error("Could not write to socket.");
	}

	return *this;
}


/*
 * ___________________________________________________________________________
 */
const Socket& Socket::operator<<(const vector<uint8_t>& data) {

	ssize_t sent = send_((const uint8_t*)&data[0], data.size());

	if (sent < 0 || (size_t)sent != data.size()) {
		throw std::runtime_error("Could not write to socket.");
	}

	return *this;
}


/*
 * ___________________________________________________________________________
 */
const Socket& Socket::operator<<(const string& s) {

	ssize_t sent = send_((const uint8_t*)s.c_str(), s.length());

	if (sent < 0 || (size_t)sent != s.length()) {
		throw std::runtime_error("Could not write to socket.");
	}

	return *this;
}


/*
 * ___________________________________________________________________________
 */
const Socket& Socket::operator>>(vector<uint8_t>& data) {

	uint8_t buf[BUFFER_SIZE];

	ssize_t read = recv_(buf, sizeof(buf));

	if (read >= 0) {
		for (size_t i = 0; i < (size_t)read; i++) {
			data.push_back(buf[i]);
		}
	} else {
		throw std::runtime_error(
				"Socket::operator>>(...): Could not read from socket");
	}

	return *this;
}


/*
 * ___________________________________________________________________________
 */
const Socket& Socket::operator>>(BufferWriter& writer) {

	uint8_t buf[BUFFER_SIZE];

	ssize_t read = recv_(buf, sizeof(buf));

	if (read >= 0) {
		for (size_t i = 0; i < (size_t)read; i++) {
			writer.appendByte(buf[i]);
		}
	} else {
		throw std::runtime_error(
				"Socket::operator>>(...): Could not read from socket");
	}

	return *this;
}


/*
 * ___________________________________________________________________________
 */
Socket::~Socket() {

	this->close();
}
