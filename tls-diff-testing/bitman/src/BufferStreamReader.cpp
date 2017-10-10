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
#include "VectorBuffer.h"
#include "BufferStreamReader.h"

using std::vector;


/*
 * ___________________________________________________________________________
 */
BufferStreamReader::BufferStreamReader(const BufferReader& reader) :
		reader_(reader), pos_(0) {
}


/*
 * ___________________________________________________________________________
 */
uint8_t BufferStreamReader::readByte_(bool remove) {

	/* bounds checked by underlying BufferReader */
	uint8_t byte = reader_.getByte(pos_);
	if (remove) {
		++pos_;
	}
	return byte;
}


/*
 * ___________________________________________________________________________
 */
bool BufferStreamReader::readBit_(bool remove) {

	/* bounds checked by underlying BufferReader */
	bool bit = reader_.getBit(pos_);
	if (remove) {
		pos_ <<= 1;
	}
	return bit;
}


/*
 * ___________________________________________________________________________
 */
BC BufferStreamReader::getLength_() const {

	BC len = reader_.getLength();
	if (len > pos_) {
		len -= pos_;
	} else {
		len = 0;
	}
	return len;
}


/*
 * ___________________________________________________________________________
 */
bool BufferStreamReader::getBit_(const BC& bc) const {

	/* bounds checked by underlying BufferReader */
	return reader_.getBit(pos_ + bc);
}


/*
 * ___________________________________________________________________________
 */
uint8_t	BufferStreamReader::getByte_(const BC& bc) const {

	/* bounds checked by underlying BufferReader */
	return reader_.getByte(pos_ + bc);
}


/*
 * ___________________________________________________________________________
 */
BC BufferStreamReader::copyTo_(BufferWriter& buffer) const {

	return BC::undef();
}


/*
 * ___________________________________________________________________________
 */
BufferStreamReader::~BufferStreamReader() {
}
