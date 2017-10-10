#include "MessageDigest.h"


/*
 * ___________________________________________________________________________
 */
MessageDigest::MessageDigest() {
}


/*
 * ___________________________________________________________________________
 */
void MessageDigest::digest(const BufferReader& message, BufferWriter& hash) {

	this->reset();
	this->update(message);
	this->finish(hash);
}


/*
 * ___________________________________________________________________________
 */
MessageDigest::~MessageDigest() {
}

