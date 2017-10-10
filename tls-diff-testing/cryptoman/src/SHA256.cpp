#include <stdexcept>
#include "SHA256.h"
#include "BufferReader.h"
#include "BufferWriter.h"


BC SHA256::digestSize_;
BC SHA256::blockSize_;


/*
 * ___________________________________________________________________________
 */
SHA256::SHA256() {
}


/*
 * ___________________________________________________________________________
 */
const BC& SHA256::getDigestSize() const {

	digestSize_ = CryptoPP::SHA256::DIGESTSIZE;
	return digestSize_;
}


/*
 * ___________________________________________________________________________
 */
const BC& SHA256::getBlockSize() const {

	SHA256::blockSize_ = CryptoPP::SHA256::BLOCKSIZE;
	return SHA256::blockSize_;
}


/*
 * ___________________________________________________________________________
 */
void SHA256::reset() {

	sha256_.Restart();
}


/*
 * ___________________________________________________________________________
 */
void SHA256::update(const BufferReader& message) {

	BC len = message.getLength();
	if (len.bit8() != 0) {
		throw std::runtime_error(
				"SHA256::update(...): Message is not byte-aligned");
	}

	size_t n = len.byte();
	uint8_t data[n];
	message.copyTo(data, n);
	sha256_.Update(data, n);
}


/*
 * ___________________________________________________________________________
 */
void SHA256::finish(BufferWriter& hash) {

	size_t n = this->getDigestSize().byte();
	uint8_t digest[n];
	sha256_.Final(digest);
	hash.appendBytes(digest, n);
}


/*
 * ___________________________________________________________________________
 */
SHA256::~SHA256() {
}

