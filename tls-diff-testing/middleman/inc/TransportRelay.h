#ifndef __TransportRelay_H__
#define __TransportRelay_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <vector>
#include <string>

using std::vector;
using std::string;

class TCPSocket;
class TCPServerSocket;
class TCPClientSocket;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class TransportRelay {

private:

	TCPServerSocket&	serverSocket_;
	TCPClientSocket&	outSocket_;
	TCPSocket*			inSocket_;

	uint8_t* buffer_;
	int bufferLen_;

	int logLevel_;
	string logPrefix_;


	void log(int minLevel, const string& msg);

	void bufferToVector(uint8_t* buffer, size_t bufferLen, vector<uint8_t>& data);


public:

	TransportRelay(int inPort, const string& destAddr, int destPort);

	void setLogPrefix(string prefix);
	void setLogLevel(int logLevel);
	int getLogLevel() const;

	bool process();
	bool close();

	ssize_t injectToServer(vector<uint8_t>& data);
	ssize_t injectToClient(vector<uint8_t>& data);

	virtual bool interceptToServer(vector<uint8_t>& data);
	virtual bool interceptToClient(vector<uint8_t>& data);

	virtual ~TransportRelay();

};

#endif
