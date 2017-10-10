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

#ifndef __TCPBatchClientSocket_H__
#define __TCPBatchClientSocket_H__

#include <stdlib.h>
#include <vector>
#include "TCPClientSocket.h"


/* =========================================================================
 *
 *
 *
 * ========================================================================= */

class TCPBatchClientSocket {

private:

	/* TODO: Add description */
	typedef std::vector<TCPClientSocket*> socket_vector_type_t;


    /* TODO: Add description */
	socket_vector_type_t sockets_;


public:

    /* TODO: Add description */
	TCPBatchClientSocket();


    /* TODO: Add description */
	bool addServer(const string& hostAndPort);

    /* TODO: Add description */
	bool addServer(const string& host, int port);

    /* TODO: Add description */
	inline size_t getNServer() const {

		return sockets_.size();
	}


	/* TODO: Add description */
	size_t connect();

    /* TODO: Add description */
	bool disconnect();

    /* TODO: Add description */
	bool close();

    /* TODO: Add description */
	bool allConnected() const;


	/* TODO: Add description */
	bool setNonBlocking(bool nonBlocking);

	/* TODO: Add description */
	void setTimeout(size_t seconds);


	/* TODO: Add description */
	const TCPBatchClientSocket& operator<<(const BufferReader& reader);


    /* TODO: Add description */
	inline TCPClientSocket& operator[](size_t index) {

		return *sockets_[index];
	}


    /* TODO: Add description */
	virtual ~TCPBatchClientSocket();

};

#endif
