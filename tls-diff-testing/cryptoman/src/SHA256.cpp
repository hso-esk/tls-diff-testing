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

