#include "errno.h"
#include <fcntl.h>
#include <stdexcept>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "BufferReader.h"
#include "BufferWriter.h"
#include "String_.h"
#include "UDPSocket.h"


/*
 * ___________________________________________________________________________
 */
UDPSocket::UDPSocket() {

	if (!this->create_()) {
		throw std::runtime_error(
				"TCPSocket(...): Could not create UDP socket.");
	}
}


/*
 * ___________________________________________________________________________
 */
UDPSocket::UDPSocket(int socket) : Socket(socket) {
}


/*
 * ___________________________________________________________________________
 */
bool UDPSocket::create_() {

	if (this->isValid()) {
		return false;
	}

	int socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (socket < 0) {
		return false;
	}

	int on = 1;
	if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR,
			(const char*)&on, sizeof(on)) == -1) {
		return false;
	}

	return this->setSocketFd_(socket);
}


/*
 * ___________________________________________________________________________
 */
ssize_t UDPSocket::send_(const uint8_t* const data, size_t len) {

	if (!this->hasRemoteAddress_()) {
		return -1;
	}

	int status = sendto(this->getSocketFd_(), data, len, 0,
			(struct sockaddr*)this->remoteAddress_(),
			this->remoteAddressSize_());

	return status;
}


/*
 * ___________________________________________________________________________
 */
ssize_t UDPSocket::recv_(uint8_t* const data, size_t maxLen) {

	return -1;
}


/*
 * ___________________________________________________________________________
 */
UDPSocket::~UDPSocket() {
}
