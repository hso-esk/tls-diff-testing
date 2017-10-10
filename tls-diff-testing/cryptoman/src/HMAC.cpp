#include <stdexcept>
#include "BufferStreamReader.h"
#include "HMAC.h"


/*
 * ___________________________________________________________________________
 */
HMAC::HMAC(MessageDigest* digest, const BufferReader& key) : digest_(digest) {

	if (digest_ == 0) {
		throw std::runtime_error(
				"HMAC(...): Invalid message digest given");
	}

	BC keyLen = key.getLength();
	if (keyLen.bit8() != 0) {
		throw std::runtime_error(
				"HMAC(...): Key is not byte-aligned");
	}

	BC digestSize = digest_->getBlockSize();
	if (keyLen > digestSize) {
		digest_->reset();
		digest_->update(key);
		digest_->finish(key_);
	} else {
		key_.appendFromBuffer(key);
		while (key_.getLength() < digestSize) {
			key_.appendByte(0x00);
		}
	}

	this->initDigest();
}


/*
 * ___________________________________________________________________________
 */
void HMAC::initDigest() {

	BufferStreamReader reader(key_);
	VectorBuffer keyiPad;
	while (reader.getLength() >= 1) {
		keyiPad.appendByte(reader.readByte() ^ 0x36);
	}

	digest_->reset();
	digest_->update(keyiPad);
}


/*
 * ___________________________________________________________________________
 */
const BC& HMAC::getDigestSize() const {

	return digest_->getDigestSize();
}


/*
 * ___________________________________________________________________________
 */
const BC& HMAC::getBlockSize() const {

	return digest_->getBlockSize();
}


/*
 * ___________________________________________________________________________
 */
void HMAC::reset() {

	digest_->reset();
	this->initDigest();
}


/*
 * ___________________________________________________________________________
 */
void HMAC::update(const BufferReader& message) {

	digest_->update(message);
}


/*
 * ___________________________________________________________________________
 */
void HMAC::finish(BufferWriter& hash) {

	VectorBuffer inner;
	digest_->finish(inner);

	BufferStreamReader reader(key_);
	VectorBuffer keyoPad;
	while (reader.getLength() >= 1) {
		keyoPad.appendByte(reader.readByte() ^ 0x5C);
	}

	digest_->reset();
	digest_->update(keyoPad);
	digest_->update(inner);
	digest_->finish(hash);
}


/*
 * ___________________________________________________________________________
 */
HMAC::~HMAC() {

	delete digest_;
}

