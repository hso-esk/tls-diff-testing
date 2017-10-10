#ifndef __UDPClientSocket_H__
#define __UDPClientSocket_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "UDPSocket.h"

#include <string>

using std::vector;
using std::string;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class UDPClientSocket : public UDPSocket {

public:

	/* TODO: Add description */
	UDPClientSocket(const string& hostAndPort);

	/* TODO: Add description */
	UDPClientSocket(const string& host, int port);


	/* TODO: Add description */
	virtual ~UDPClientSocket();

};

#endif
