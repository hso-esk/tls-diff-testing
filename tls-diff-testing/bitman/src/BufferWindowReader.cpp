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
#include "BufferWindowReader.h"

using std::vector;


/*
 * ___________________________________________________________________________
 */
BufferWindowReader::BufferWindowReader(
		const BufferReader& reader, BC offset, BC length) :
		reader_(reader), offset_(offset), length_(length) {
}


/*
 * ___________________________________________________________________________
 */
BC BufferWindowReader::getLength_() const {

	BC len = reader_.getLength();
	if (len > offset_) {
		len -= offset_;
	} else {
		len = 0;
	}
	return BC::getMin(len, length_);
}


/*
 * ___________________________________________________________________________
 */
bool BufferWindowReader::getBit_(const BC& bc) const {

	if (bc < this->getLength()) {
		return reader_.getBit(offset_ + bc);
	} else {
		throw std::runtime_error(
				"BufferWindowReader::getBit(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
uint8_t	BufferWindowReader::getByte_(const BC& bc) const {

	if ((bc + 1) <= this->getLength()) {
		return reader_.getByte(offset_ + bc);
	} else {
		throw std::runtime_error(
				"BufferWindowReader::getByte(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
BC BufferWindowReader::copyTo_(BufferWriter& buffer) const {

	return BC::undef();
}


/*
 * ___________________________________________________________________________
 */
BufferWindowReader::~BufferWindowReader() {
}
