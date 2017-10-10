#ifndef __Socket_H__
#define __Socket_H__

#include <stdlib.h>
#include <inttypes.h>
#include <vector>
#include <string>
#include "BC.h"

class BufferReader;
class BufferWriter;

using std::vector;
using std::string;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class Socket {

private:

	/* TODO: Add description */
	int	socket_;

	/* TODO: Add description */
	BC	bcIn_;

	/* TODO: Add description */
	BC	bcOut_;


	/* TODO: Add description */
	bool hasRemoteAddr_;

	/* TODO: Add description */
	struct sockaddr_in remoteAddr_;

	/* TODO: Add description */
	size_t timeoutSecs_;


protected:

	/* TODO: Add description */
	inline int getSocketFd_() const {

		return socket_;
	}

	/* TODO: Add description */
	bool setSocketFd_(int socket);


	/* TODO: Add description */
	inline struct sockaddr_in* remoteAddress_() {

		return &remoteAddr_;
	}

	/* TODO: Add description */
	inline size_t remoteAddressSize_() const {

		return sizeof(remoteAddr_);
	}

	/* TODO: Add description */
	inline bool hasRemoteAddress_() const {

		return hasRemoteAddr_;
	}


	/* TODO: Add description */
	virtual ssize_t send_(const uint8_t* const data, size_t len) = 0;

	/* TODO: Add description */
	virtual ssize_t recv_(uint8_t* const data, size_t maxLen) = 0;


public:

	/* TODO: Add description */
	Socket();

	/* TODO: Add description */
	Socket(int socket);


	/* TODO: Add description */
	inline bool isValid() const {

		return (socket_ != -1);
	}


	/* TODO: Add description */
	bool setNonBlocking(bool nonBlocking);

	/* TODO: Add description */
	void setTimeout(size_t seconds);

	/* TODO: Add description */
	bool setRemoteAddress(const string& hostAndPort);

	/* TODO: Add description */
	bool setRemoteAddress(const string& host, int port);


	/* TODO: Add description */
	bool close();


	/* TODO: Add description */
    int getAvailableData() const;


	/* TODO: Add description */
	const Socket& operator<<(const BufferReader& reader);

	/* TODO: Add description */
	const Socket& operator<<(const vector<uint8_t>& data);

	/* TODO: Add description */
	const Socket& operator<<(const string& s);


	/* TODO: Add description */
	const Socket& operator>>(BufferWriter& writer);

	/* TODO: Add description */
	const Socket& operator>>(vector<uint8_t>& data);


	/* TODO: Add description */
	virtual ~Socket();

};

#endif
