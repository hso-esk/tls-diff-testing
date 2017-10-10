/*
 *  Copyright (C) 2017
 *  Andreas Walz [andreas.walz@hs-offenburg.de]
 *  Offenburg University of Applied Sciences
 *  Institute of Reliable Embedded Systems and Communications Electronics (ivESK)
 *  [https://ivesk.hs-offenburg.de/]
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

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

