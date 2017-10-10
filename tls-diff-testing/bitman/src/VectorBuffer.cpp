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

#include "VectorBuffer.h"
#include <stdexcept>

using std::vector;


/*
 * ___________________________________________________________________________
 */
VectorBuffer::VectorBuffer() : Buffer(), bitOff_(0) {
}


/*
 * ___________________________________________________________________________
 */
VectorBuffer::VectorBuffer(const BC& capacity) : Buffer(capacity), bitOff_(0) {

	if (capacity.isDef()) {
		/* avoid reallocations while filling buffer of known capacity */
		data_.reserve(capacity.byteCeil());
	}
}


/*
 * ___________________________________________________________________________
 */
bool VectorBuffer::getBit_(const BC& bc) const {

	if (bc < this->getLength()) {
		return getBitUnsafe(bc.byte(), bc.bit8());
	} else {
		throw std::runtime_error("VectorBuffer::getBit(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
uint8_t	VectorBuffer::getByte_(const BC& bc) const {

	if ((bc + 1) <= this->getLength()) {
		return getByteUnsafe(bc.byte(), bc.bit8());
	} else {
		throw std::runtime_error("VectorBuffer::getByte(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
BC VectorBuffer::copyTo_(BufferWriter& buffer) const {

	BC len = this->getLength();
	
    /* copy full bytes */
    BC bc = 0;
    while ((bc + 1) <= len) {
        buffer.appendByte(getByteUnsafe(bc.byte(), bc.bit8()));
        ++bc;
    }
    /* if necessary: copy remaining bits */
    while (bc < len) {
        buffer.appendBit(getBitUnsafe(bc.byte(), bc.bit8()));
        bc <<= 1;
    }

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC VectorBuffer::getLength_() const {

	BC len;
	if (bitOff_ > 0) {
		len = data_.size() - 1;
		len <<= bitOff_;
	} else {
		len = data_.size();
	}
	return len;
}


/*
 * ___________________________________________________________________________
 */
bool VectorBuffer::appendBit(bool bit) {

	bool success = false;

	BC capacity = this->getCapacity();
	if (capacity.isUndef() || this->getLength() < capacity) {

		if (bitOff_ != 0) {
			/* this operation doesn't need to add another
			 * byte if the array is not byte-aligned */
			uint8_t byte = bit ? 1 : 0;
			data_[data_.size() - 1] |= (byte << (7 - bitOff_)) & 0xFF;
		} else {
			data_.push_back(bit ? 0x80 : 0);
		}

		/* remember that a bit has been added */
		bitOff_++;
		if (bitOff_ > 7) {
			bitOff_ = 0;
		}

		success = true;
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool VectorBuffer::appendByte(uint8_t byte) {

	bool success = false;

	BC capacity = this->getCapacity();
	if (capacity.isUndef() || (this->getLength() + 1) <= capacity) {

		if (bitOff_ == 0) {
			/* the operation is easy if the current bit offset is zero */
			data_.push_back(byte);
			success = true;
		} else if (bitOff_ < 8 && data_.size() > 0) {
			data_[data_.size() - 1] |= (byte >> bitOff_) & 0xFF;
			data_.push_back((byte << (8 - bitOff_)) & 0xFF);
			success = true;
		} else {
			/* this should never happen */
			throw std::runtime_error(
					"VectorBuffer::appendByte(...): Invalid internal state");
		}

	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool VectorBuffer::setBit(const BC& bc, bool bit) {

	bool ret = false;

	if (bc.isDef() && bc < this->getLength()) {
		size_t posByte = bc.byte();
		size_t posBit = bc.bit8();
		if (bit) {
			data_[posByte] |= 0x01 << (7 - posBit);
		} else {
			data_[posByte] &= ~(0x01 << (7 - posBit));
		}
		ret = true;
	}

	return ret;
}


/*
 * ___________________________________________________________________________
 */
bool VectorBuffer::setByte(const BC& bc, uint8_t byte) {

	bool ret = false;

	if (bc.isDef() && (bc + 1) <= this->getLength()) {
		size_t posByte = bc.byte();
		size_t posBit = bc.bit8();
		if (posBit == 0) {
			data_[posByte] = byte;
		} else {
			uint8_t data = data_[posByte] & (0xFF << (8 - posBit)) & 0xFF;
			data_[posByte] = data | (byte >> posBit);
			data = data_[posByte + 1] & (0xFF >> posBit) & 0xFF;
			data_[posByte + 1] = data | (byte << (8 - posBit));
		}
		ret = true;
	}

	return ret;
}


/*
 * ___________________________________________________________________________
 */
void VectorBuffer::clear() {

	data_.clear();
	bitOff_ = 0;
}


/*
 * ___________________________________________________________________________
 */
void VectorBuffer::truncate(const BC& length) {

	/* TODO: allow to truncate to inter-byte lengths */

	BC myLength = this->getLength();
	if (length < myLength) {
		size_t n = data_.size() - length.byteCeil();
		for (size_t i = 0; i < n; i++) {
			data_.pop_back();
		}
		bitOff_ = length.bit8();
	}
}


/*
 * ___________________________________________________________________________
 */
const uint8_t* VectorBuffer::getDataPointer() const {

    return &(data_[0]);
}


/*
 * ___________________________________________________________________________
 */
VectorBuffer::~VectorBuffer() {
}
