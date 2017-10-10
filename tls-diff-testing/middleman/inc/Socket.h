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

#ifndef __Socket_H__
#define __Socket_H__

#include <stdlib.h>
#include <inttypes.h>
#include <vector>
#include <string>
#include "BC.h"

class BufferReader;
class BufferWriter;

using std::vector;
using std::string;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class Socket {

private:

	/* TODO: Add description */
	int	socket_;

	/* TODO: Add description */
	BC	bcIn_;

	/* TODO: Add description */
	BC	bcOut_;


	/* TODO: Add description */
	bool hasRemoteAddr_;

	/* TODO: Add description */
	struct sockaddr_in remoteAddr_;

	/* TODO: Add description */
	size_t timeoutSecs_;


protected:

	/* TODO: Add description */
	inline int getSocketFd_() const {

		return socket_;
	}

	/* TODO: Add description */
	bool setSocketFd_(int socket);


	/* TODO: Add description */
	inline struct sockaddr_in* remoteAddress_() {

		return &remoteAddr_;
	}

	/* TODO: Add description */
	inline size_t remoteAddressSize_() const {

		return sizeof(remoteAddr_);
	}

	/* TODO: Add description */
	inline bool hasRemoteAddress_() const {

		return hasRemoteAddr_;
	}


	/* TODO: Add description */
	virtual ssize_t send_(const uint8_t* const data, size_t len) = 0;

	/* TODO: Add description */
	virtual ssize_t recv_(uint8_t* const data, size_t maxLen) = 0;


public:

	/* TODO: Add description */
	Socket();

	/* TODO: Add description */
	Socket(int socket);


	/* TODO: Add description */
	inline bool isValid() const {

		return (socket_ != -1);
	}


	/* TODO: Add description */
	bool setNonBlocking(bool nonBlocking);

	/* TODO: Add description */
	void setTimeout(size_t seconds);

	/* TODO: Add description */
	bool setRemoteAddress(const string& hostAndPort);

	/* TODO: Add description */
	bool setRemoteAddress(const string& host, int port);


	/* TODO: Add description */
	bool close();


	/* TODO: Add description */
    int getAvailableData() const;


	/* TODO: Add description */
	const Socket& operator<<(const BufferReader& reader);

	/* TODO: Add description */
	const Socket& operator<<(const vector<uint8_t>& data);

	/* TODO: Add description */
	const Socket& operator<<(const string& s);


	/* TODO: Add description */
	const Socket& operator>>(BufferWriter& writer);

	/* TODO: Add description */
	const Socket& operator>>(vector<uint8_t>& data);


	/* TODO: Add description */
	virtual ~Socket();

};

#endif
