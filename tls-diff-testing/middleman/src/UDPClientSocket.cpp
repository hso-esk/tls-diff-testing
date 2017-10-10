#include "UDPClientSocket.h"
#include <stdexcept>


/*
 * ___________________________________________________________________________
 */
UDPClientSocket::UDPClientSocket(const string& hostAndPort) {

	if (!this->setRemoteAddress(hostAndPort)) {
		throw std::runtime_error(
				"UDPClientSocket(...): Failed to resolve host address");
	}
}


/*
 * ___________________________________________________________________________
 */
UDPClientSocket::UDPClientSocket(const string& host, int port) {

	if (!this->setRemoteAddress(host, port)) {
		throw std::runtime_error(
				"UDPClientSocket(...): Failed to resolve host address");
	}
}


/*
 * ___________________________________________________________________________
 */
UDPClientSocket::~UDPClientSocket() {
}
