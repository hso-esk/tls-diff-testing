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
#include "DequeRingBuffer.h"

using std::vector;
using std::deque;


/*
 * ___________________________________________________________________________
 */
DequeRingBuffer::DequeRingBuffer() :
		RingBuffer(), writeBitOff_(0), readBitOff_(0) {
}


/*
 * ___________________________________________________________________________
 */
DequeRingBuffer::DequeRingBuffer(const BC& capacity) :
		RingBuffer(capacity), writeBitOff_(0), readBitOff_(0) {
}


/*
 * ___________________________________________________________________________
 */
bool DequeRingBuffer::getBit_(const BC& bc) const {

	if (bc < this->getLength()) {
		BC dpoff = bc;
		dpoff <<= readBitOff_;
		return (data_.at(dpoff.byte()) & (0x80 >> dpoff.bit8())) != 0;
	} else {
		throw std::runtime_error("DequeRingBuffer::getBit(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
uint8_t	DequeRingBuffer::getByte_(const BC& bc) const {

	if ((bc + 1) <= this->getLength()) {
		BC dpoff = bc;
		dpoff <<= readBitOff_;
		size_t byte = dpoff.byte();
		size_t bit8 = dpoff.bit8();
		uint8_t val = (data_.at(byte) << bit8) & 0xFF;
		if (bit8 != 0) {
			val &= (0xFF00 >> (8 - bit8)) & 0xFF;
			val |= (data_.at(byte + 1) >> (8 - bit8));
		}
		return val;
	} else {
		throw std::runtime_error("DequeRingBuffer::getByte(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
BC DequeRingBuffer::copyTo_(BufferWriter& buffer) const {

	return BC::undef();
}


/*
 * ___________________________________________________________________________
 */
BC DequeRingBuffer::getLength_() const {

	BC len;
	if (writeBitOff_ > 0) {
		len = data_.size() - 1;
		len <<= writeBitOff_;
	} else {
		len = data_.size();
	}
	if (readBitOff_ > 0) {
		len >>= readBitOff_;
	}
	return len;
}


/*
 * ___________________________________________________________________________
 */
uint8_t DequeRingBuffer::readByte_(bool remove) {

	if (this->getLength() >= 1) {
		uint8_t val = (data_.front() << readBitOff_) & 0xFF;
		if (readBitOff_ != 0) {
			val = (data_.front() << readBitOff_) & 0xFF;
			val &= (0xFF00 >> (8 - readBitOff_)) & 0xFF;
			val |= (data_.at(1) >> (8 - readBitOff_));
		}
		if (remove) {
			data_.pop_front();
		}
		return val;
	} else {
		throw std::runtime_error(
				"DequeRingBuffer::readByte(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
bool DequeRingBuffer::readBit_(bool remove) {

	if (this->getLength() > 0) {
		bool val = (data_.front() & (0x80 >> readBitOff_)) != 0;
		if (remove) {
			readBitOff_++;
			if (readBitOff_ > 7) {
				data_.pop_front();
				readBitOff_ = 0;
			}
		}
		return val;
	} else {
		throw std::runtime_error(
				"DequeRingBuffer::readBit_(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
bool DequeRingBuffer::appendBit(bool bit) {

	bool success = false;

	BC capacity = this->getCapacity();
	if (capacity.isUndef() || this->getLength() < capacity) {

		if (writeBitOff_ != 0) {
			/* this operation doesn't need to add another
			 * byte if the array is not byte-aligned */
			uint8_t byte = bit ? 1 : 0;
			data_.back() |= (byte << (7 - writeBitOff_)) & 0xFF;
		} else {
			data_.push_back(bit ? 0x80 : 0);
		}

		/* remember that a bit has been added */
		writeBitOff_++;
		if (writeBitOff_ > 7) {
			writeBitOff_ = 0;
		}

		success = true;
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool DequeRingBuffer::appendByte(uint8_t byte) {

	bool success = false;

	BC capacity = this->getCapacity();
	if (capacity.isUndef() || (this->getLength() + 1) <= capacity) {

		if (writeBitOff_ == 0) {
			/* the operation is easy if the current bit offset is zero */
			data_.push_back(byte);
			success = true;
		} else if (writeBitOff_ < 8 && data_.size() > 0) {
			data_.back() |= (byte >> writeBitOff_) & 0xFF;
			data_.push_back((byte << (8 - writeBitOff_)) & 0xFF);
			success = true;
		} else {
			/* this should never happen */
			throw std::runtime_error(
					"DequeRingBuffer::appendByte(...): Invalid internal state");
		}
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool DequeRingBuffer::setBit(const BC& bc, bool bit) {

	throw std::runtime_error(
			"DequeRingBuffer::setBit(...): Not implemented");
}


/*
 * ___________________________________________________________________________
 */
bool DequeRingBuffer::setByte(const BC& bc, uint8_t byte) {

	throw std::runtime_error(
			"DequeRingBuffer::setByte(...): Not implemented");
}


/*
 * ___________________________________________________________________________
 */
void DequeRingBuffer::clear_() {

	data_.clear();
	writeBitOff_ = 0;
	readBitOff_ = 0;
}


/*
 * ___________________________________________________________________________
 */
DequeRingBuffer::~DequeRingBuffer() {
}
