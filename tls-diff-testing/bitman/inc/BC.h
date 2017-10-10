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

#ifndef __BC_H__
#define __BC_H__

#include <cstdlib>
#include <inttypes.h>
#include <string>


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class BC {

private:

	ssize_t p_;

public:

	/* TODO: Add description */
	static const BC& getMin(const BC& bc1, const BC& bc2);

	/* TODO: Add description */
	static const BC& getMax(const BC& bc1, const BC& bc2);

	/* TODO: Add description */
	inline static BC undef() {

		return BC();
	}


	/* TODO: Add description */
	BC();

	/* TODO: Add description */
	BC(ssize_t byte);

	/* TODO: Add description */
	BC(ssize_t byte, ssize_t bit);

	size_t	byte() const;
	size_t	byteCeil() const;
	size_t	byteAligned() const;
	size_t	bit() const;
	size_t	bit8() const;


	/* TODO: Add description */
	inline const BC& getWithDefault(const BC& deflt) const {
        
        return (p_ >= 0) ? *this : deflt;
    }


	/* TODO: Add description */
	inline bool isDef() const {

		return (p_ >= 0);
	}

	/* TODO: Add description */
	inline bool isUndef() const {

		return (p_ < 0);
	}

	/* TODO: Add description */
	inline bool isMultipleOf(const BC& bc) const {

		return p_ >= 0 && bc.p_ > 0 && (p_ % bc.p_) == 0;
	}

	/* TODO: Add description */
	inline bool operator==(const BC& bc) const {

		return (p_ == bc.p_ || (p_ < 0 && bc.p_ < 0));
	}

	/* TODO: Add description */
	inline bool operator==(ssize_t bytes) const {

		return (bytes >= 0) ? (p_ == bytes * 8) : (p_ == -1);
	}

	/* TODO: Add description */
	inline bool operator!=(const BC& bc) const {

		return !((*this) == bc);
	}

	/* TODO: Add description */
	inline bool operator!=(ssize_t bytes) const {

		return !((*this) == bytes);
	}

	/* TODO: Add description */
	inline bool operator<=(const BC& bc) const {

		return ((*this) == bc) || ((*this) < bc);
	}

	/* TODO: Add description */
	inline bool operator<=(size_t bytes) const {

		return ((*this) == bytes) || ((*this) < bytes);
	}

	/* TODO: Add description */
	inline bool operator>=(const BC& bc) const {

		return ((*this) == bc) || ((*this) > bc);
	}

	/* TODO: Add description */
	inline bool operator>=(size_t bytes) const {

		return ((*this) == bytes) || ((*this) > bytes);
	}

	/* TODO: Add description */
	bool operator<(const BC& bc) const;

	/* TODO: Add description */
	bool operator<(size_t bytes) const;

	/* TODO: Add description */
	bool operator>(const BC& bc) const;

	/* TODO: Add description */
	bool operator>(size_t bytes) const;


	/* TODO: Add description */
	inline BC& operator=(ssize_t bytes) {

		p_ = (bytes >= 0) ? (bytes * 8) : -1;
		return *this;
	}

	/* TODO: Add description */
	inline BC& operator+=(const BC& bc) {

		p_ = (bc.p_ >= 0 && p_ >= 0) ? (p_ + bc.p_) : -1;
		return *this;
	}

	/* TODO: Add description */
	BC&	operator+=(size_t bytes);

	/* TODO: Add description */
	BC& operator<<=(const BC& bc);

	/* TODO: Add description */
	BC& operator<<=(size_t bits);

	/* TODO: Add description */
	BC& operator++ (); // prefix ++

	/* TODO: Add description */
	BC operator++ (int); // postfix ++


	/* TODO: Add description */
	BC operator+(const BC& bc) const;

	/* TODO: Add description */
	BC operator+(size_t bytes) const;

	/* TODO: Add description */
	BC operator<<(const BC& bc) const;

	/* TODO: Add description */
	BC operator<<(size_t bits) const;


	/* TODO: Add description */
	BC& operator-=(const BC& bc);

	/* TODO: Add description */
	BC& operator-=(size_t bytes);

	/* TODO: Add description */
	BC& operator>>=(const BC& bc);

	/* TODO: Add description */
	BC& operator>>=(size_t bits);

	/* TODO: Add description */
	BC& operator-- (); // prefix --

	/* TODO: Add description */
	BC operator-- (int); // postfix --


	/* TODO: Add description */
	BC operator-(const BC& bc) const;

	/* TODO: Add description */
	BC operator-(size_t bytes) const;

	/* TODO: Add description */
	BC operator>>(const BC& bc) const;

	/* TODO: Add description */
	BC operator>>(size_t bits) const;


	/* TODO: Add description */
	BC floor(const BC& multipleOf) const;

	/* TODO: Add description */
	BC ceil(const BC& multipleOf) const;


	/* TODO: Add description */
	std::string	toString() const;

	/* TODO: Add description */
	std::string toStringDefault(const std::string& deflt) const;

	/* TODO: Add description */
	void print() const;

};

#endif
