#ifndef __TCPClientSocket_H__
#define __TCPClientSocket_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <string>
#include "TCPSocket.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class TCPClientSocket : public TCPSocket {

public:

	/* TODO: Add description */
	TCPClientSocket(const string& hostAndPort);

	/* TODO: Add description */
	TCPClientSocket(const string& host, int port);


	/* TODO: Add description */
	bool connect();


	/* TODO: Add description */
	virtual ~TCPClientSocket();

};

#endif
