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
