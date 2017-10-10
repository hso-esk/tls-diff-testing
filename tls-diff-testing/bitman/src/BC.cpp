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
#include <iostream>
#include "String_.h"
#include "BC.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
const BC& BC::getMin(const BC& bc1, const BC& bc2) {

	if (bc1.isDef() && bc2.isDef()) {
		/* return the smaller one */
		return (bc1 < bc2) ? bc1 : bc2;
	} else {
		/* return the defined one */
		return bc1.isDef() ? bc1 : bc2;
	}
}


/*
 * ___________________________________________________________________________
 */
const BC& BC::getMax(const BC& bc1, const BC& bc2) {

	if (bc1.isDef() && bc2.isDef()) {
		/* return the larger one */
		return (bc1 > bc2) ? bc1 : bc2;
	} else {
		/* return the defined one */
		return bc1.isDef() ? bc1 : bc2;
	}
}


/*
 * ___________________________________________________________________________
 */
BC::BC() : p_(-1) {
}


/*
 * ___________________________________________________________________________
 */
BC::BC(ssize_t byte) {

	if (byte >= 0) {
		p_ = byte * 8;
	} else {
		p_ = -1;
	}
}


/*
 * ___________________________________________________________________________
 */
BC::BC(ssize_t byte, ssize_t bit) {

	if (byte >= 0 && bit >= 0) {
		p_ = (byte >= 0) ? byte * 8 : 0;
		p_ += (bit >= 0) ? bit : 0;
	} else {
		p_ = -1;
	}
}


/*
 * ___________________________________________________________________________
 */
size_t BC::byte() const {

	if (p_ >= 0) {
		return p_ / 8;
	} else {
		throw std::runtime_error("BC::byte(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
size_t BC::byteCeil() const {

	if (p_ >= 0) {
		return (p_ % 8) > 0 ? (p_ / 8) + 1 : p_ / 8;
	} else {
		throw std::runtime_error("BC::byteCeil(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
size_t BC::byteAligned() const {

	if (p_ >= 0) {
		if ((p_ % 8) != 0) {
			throw std::runtime_error("BC::byteAligned(): Value not byte-aligned");
		} else {
			return p_ / 8;
		}
	} else {
		throw std::runtime_error("BC::byteAligned(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
size_t BC::bit() const {

	if (p_ >= 0) {
		return p_;
	} else {
		throw std::runtime_error("BC::bit(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
size_t BC::bit8() const {

	if (p_ >= 0) {
		return p_ % 8;
	} else {
		throw std::runtime_error("BC::bit8(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
bool BC::operator<(const BC& bc) const {

	if (p_ >= 0 && bc.p_ >= 0) {
		return (p_ < bc.p_);
	} else {
		throw std::runtime_error("BC::operator<(...): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
bool BC::operator<(size_t bytes) const {

	if (p_ >= 0) {
		return (p_ < (ssize_t)bytes * 8);
	} else {
		throw std::runtime_error("BC::operator<(...): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
bool BC::operator>(const BC& bc) const {

	if (p_ >= 0 && bc.p_ >= 0) {
		return (p_ > bc.p_);
	} else {
		throw std::runtime_error("BC::operator>(...): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
bool BC::operator>(size_t bytes) const {

	if (p_ >= 0) {
		return (p_ > (ssize_t)bytes * 8);
	} else {
		throw std::runtime_error("BC::operator>(...): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator+=(size_t bytes) {

	if (p_ >= 0) {
		p_ += bytes * 8;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator++() {

	if (p_ >= 0) {
		p_ += 8;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator++(int) {

	BC bc = *this;
	if (p_ >= 0) {
		p_ += 8;
	}
	return bc;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator+(const BC& bc) const {

	BC ret = *this;
	ret += bc;
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator+(size_t bytes) const {

	BC ret = *this;
	ret += bytes;
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator<<(const BC& bc) const {

	BC ret = *this;
	ret += bc;
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator<<(size_t bits) const {

	BC ret = *this;
	ret <<= bits;
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator<<=(const BC& bc) {

	if (bc.p_ >= 0 && p_ >= 0) {
		p_ += bc.p_;
	} else {
		p_ = -1;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator<<=(size_t bits) {

	if (p_ >= 0) {
		p_ += bits;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator-=(const BC& bc) {

	if (bc.p_ >= 0 && p_ >= 0 && p_ >= bc.p_) {
		p_ -= bc.p_;
	} else {
		p_ = -1;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator-=(size_t bytes) {

	if (p_ >= 0 && p_ >= (ssize_t)bytes * 8) {
		p_ -= (ssize_t)bytes * 8;
	} else {
		p_ = -1;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator>>=(const BC& bc) {

	if (bc.p_ >= 0 && p_ >= 0 && p_ >= bc.p_) {
		p_ -= bc.p_;
	} else {
		p_ = -1;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator>>=(size_t bits) {

	if (p_ >= 0 && p_ >= (ssize_t)bits) {
		p_ -= (ssize_t)bits;
	} else {
		p_ = -1;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC& BC::operator--() {

	if (p_ >= 8) {
		p_ -= 8;
	} else {
		p_ = -1;
	}
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator--(int) {

	BC bc = *this;
	if (p_ >= 8) {
		p_ -= 8;
	} else {
		p_ = -1;
	}
	return bc;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator-(const BC& bc) const {

	BC ret = *this;
	ret -= bc;
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator-(size_t bytes) const {

	BC ret = *this;
	ret -= bytes;
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator>>(const BC& bc) const {

	BC ret = *this;
	ret -= bc;
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC BC::operator>>(size_t bits) const {

	BC ret = *this;
	ret >>= bits;
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC BC::floor(const BC& multipleOf) const {

	BC ret = *this;
	if (ret.p_ >= 0 && multipleOf.p_ >= 0) {
		ret.p_ -= ret.p_ % multipleOf.p_;
	}
	return ret;
}


/*
 * ___________________________________________________________________________
 */
BC BC::ceil(const BC& multipleOf) const {

	BC ret = *this;
	if (ret.p_ >= 0 && multipleOf.p_ >= 0 && ((ret.p_ % multipleOf.p_) != 0)) {
		ret.p_ += multipleOf.p_ - (ret.p_ % multipleOf.p_);
	}
	return ret;
}


/*
 * ___________________________________________________________________________
 */
string BC::toString() const {

	String str;
	if (p_ < 0) {
		str = "undef";
	} else {
		str = String::format("%d", p_ / 8);
		size_t mod = p_ % 8;
		if (mod > 0) {
			str.appendFormat(".%d", mod);
		}
	}
	return str;
}


/*
 * ___________________________________________________________________________
 */
string BC::toStringDefault(const string& deflt) const {

	String str;
	if (p_ < 0) {
		str = deflt;
	} else {
		str = this->toString();
	}
	return str;
}


/*
 * ___________________________________________________________________________
 */
void BC::print() const {

	std::cout << this->toString() << std::endl;
}
