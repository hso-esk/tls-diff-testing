#ifndef __TCPSocket_H__
#define __TCPSocket_H__

#include <stdlib.h>
#include <inttypes.h>
#include <vector>
#include <string>
#include "Socket.h"

class BufferReader;
class BufferWriter;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class TCPSocket : public Socket {

protected:

    /* TODO: Add description */
	bool connected_;

    /* TODO: Add description */
	bool create_();

    /* TODO: Add description */
	ssize_t send_(const uint8_t* const data, size_t len);

    /* TODO: Add description */
	ssize_t recv_(uint8_t* const data, size_t maxLen);


public:

    /* TODO: Add description */
	TCPSocket();

    /* TODO: Add description */
	TCPSocket(int socket);


    /* TODO: Add description */
	inline bool isConnected() const {

		return this->isValid() && connected_;
	}


    /* TODO: Add description */
	bool disconnect();


    /* TODO: Add description */
	virtual ~TCPSocket();

};

#endif
