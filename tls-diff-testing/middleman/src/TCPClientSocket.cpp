#include "TCPClientSocket.h"
#include "String_.h"
#include "errno.h"
#include <fcntl.h>
#include <stdexcept>

using std::vector;
using std::string;


/*
 * ___________________________________________________________________________
 */
TCPClientSocket::TCPClientSocket(const string& hostAndPort) {

	if (!this->setRemoteAddress(hostAndPort)) {
		throw std::runtime_error(
				"TCPClientSocket(...): Failed to resolve host address");
	}
}


/*
 * ___________________________________________________________________________
 */
TCPClientSocket::TCPClientSocket(const string& host, int port) {

	if (!this->setRemoteAddress(host, port)) {
		throw std::runtime_error(
				"TCPClientSocket(...): Failed to resolve host address");
	}
}


/*
 * ___________________________________________________________________________
 */
bool TCPClientSocket::connect() {

	if (!this->isValid() && !this->create_()) {
		return false;
	}

	int status = ::connect(this->getSocketFd_(),
			(sockaddr*)this->remoteAddress_(), this->remoteAddressSize_());
	if (status == 0) {
		connected_ = true;
	}

	return this->isConnected();
}


/*
 * ___________________________________________________________________________
 */
TCPClientSocket::~TCPClientSocket() {
}
