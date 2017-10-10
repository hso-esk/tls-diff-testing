#ifndef __TCPServerSocket_H__
#define __TCPServerSocket_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "TCPSocket.h"

#include <vector>
#include <string>

using std::vector;
using std::string;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class TCPServerSocket : public TCPSocket {

private:

	int		port_;

	bool	bind_(int port);
	bool	listen_(int maxConnections = 5) const;
	int		accept_() const;


public:

	TCPServerSocket();
	TCPServerSocket(int port);

	TCPSocket* accept();

	virtual ~TCPServerSocket();

};

#endif
