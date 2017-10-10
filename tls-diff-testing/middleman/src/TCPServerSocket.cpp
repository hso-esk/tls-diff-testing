#include "TCPServerSocket.h"
#include "String_.h"
#include "errno.h"
#include <fcntl.h>
#include <stdexcept>


/*
 * ___________________________________________________________________________
 */
TCPServerSocket::TCPServerSocket(int port) {

	port_ = port;

	if (!this->bind_(port)) {
		throw std::runtime_error(
				"TCPServerSocket(...): Could not bind to port.");
	}
	if (!this->listen_()) {
		throw std::runtime_error(
				"TCPServerSocket(...): Could not listen to socket.");
	}
}


/*
 * ___________________________________________________________________________
 */
bool TCPServerSocket::bind_(int port) {

	if (!this->isValid()) {
		return false;
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);

	int bind_return = ::bind(this->getSocketFd_(),
			(struct sockaddr*)&addr, sizeof(addr));

	return (bind_return != -1);
}


/*
 * ___________________________________________________________________________
 */
bool TCPServerSocket::listen_(int maxConnections) const {

	if (!this->isValid()) {
		return false;
	}

	int listen_return = ::listen(this->getSocketFd_(), maxConnections);

	return (listen_return != -1);
}


/*
 * ___________________________________________________________________________
 */
int TCPServerSocket::accept_() const {

	if (!this->isValid()) {
		return false;
	}

	sockaddr_in addr;
	socklen_t addr_length = (socklen_t)sizeof(addr);

	return ::accept(this->getSocketFd_(), (sockaddr*)&addr, &addr_length);
}


/*
 * ___________________________________________________________________________
 */
TCPSocket* TCPServerSocket::accept() {

	TCPSocket* srvSock = (TCPSocket*)0;

	int socket = accept_();
	if (socket > 0) {
		srvSock = new TCPSocket(socket);
	}

	return srvSock;
}


/*
 * ___________________________________________________________________________
 */
TCPServerSocket::~TCPServerSocket() {
}
