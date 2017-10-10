#ifndef __UDPSocket_H__
#define __UDPSocket_H__

#include <stdlib.h>
#include <inttypes.h>
#include <vector>
#include <string>
#include "Socket.h"

class BufferReader;
class BufferWriter;

using std::vector;
using std::string;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class UDPSocket : public Socket {

protected:

	bool create_();

	ssize_t send_(const uint8_t* const data, size_t len);
	ssize_t recv_(uint8_t* const data, size_t maxLen);


public:

	UDPSocket();
	UDPSocket(int socket);

	virtual ~UDPSocket();

};

#endif
