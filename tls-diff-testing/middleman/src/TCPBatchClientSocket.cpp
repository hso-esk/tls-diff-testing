#include "TCPBatchClientSocket.h"
#include "BufferReader.h"


/*
 * ___________________________________________________________________________
 */
TCPBatchClientSocket::TCPBatchClientSocket() {


}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::addServer(const string& hostAndPort) {

	sockets_.push_back(new TCPClientSocket(hostAndPort));
	return true;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::addServer(const string& host, int port) {

	sockets_.push_back(new TCPClientSocket(host, port));
	return true;
}


/*
 * ___________________________________________________________________________
 */
size_t TCPBatchClientSocket::connect() {

	size_t n = 0;

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		if ((*it)->connect()) {
			++n;
		}
	}

	return n;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::disconnect() {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		(*it)->disconnect();
	}

	return true;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::close() {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		(*it)->close();
	}

	return true;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::allConnected() const {

    bool connected = (sockets_.size() > 0);

	for (socket_vector_type_t::const_iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		if (!(*it)->isConnected()) {
            connected = false;
        }
	}

	return connected;
}


/*
 * ___________________________________________________________________________
 */
bool TCPBatchClientSocket::setNonBlocking(bool nonBlocking) {

	bool success = true;

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		if (!(*it)->setNonBlocking(nonBlocking)) {
			success = false;
		}
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
void TCPBatchClientSocket::setTimeout(size_t seconds) {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		(*it)->setTimeout(seconds);
	}
}


/*
 * ___________________________________________________________________________
 */
const TCPBatchClientSocket& TCPBatchClientSocket::operator<<(
		const BufferReader& reader) {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		if ((*it)->isConnected()) {
			*(*it) << reader;
		}
	}

	return *this;
}


/*
 * ___________________________________________________________________________
 */
TCPBatchClientSocket::~TCPBatchClientSocket() {

	for (socket_vector_type_t::iterator it = sockets_.begin();
			it != sockets_.end(); ++it) {

		delete *it;
	}
}

