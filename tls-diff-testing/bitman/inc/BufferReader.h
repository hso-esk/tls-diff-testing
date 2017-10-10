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

#ifndef __BufferReader_H__
#define __BufferReader_H__

#include <string>
#include <vector>
#include "BC.h"

class String;
class BufferWriter;
class BufferWindowReader;


/* =========================================================================
 *
 *
 *
 * ========================================================================= */

class BufferReader {

protected:

	/* === To be implemented by sub-classes: =============================== */

	/* TODO: Add description */
	virtual bool getBit_(const BC& bc) const = 0;

	/* TODO: Add description */
	virtual uint8_t getByte_(const BC& bc) const = 0;

	/* TODO: Add description */
	virtual BC copyTo_(BufferWriter& buffer) const = 0;

	/* TODO: Add description */
	virtual BC getLength_() const = 0;

	/* ===================================================================== */


public:

	/* TODO: Add description */
	BufferReader();


	/* TODO: Add description */
	inline bool getBit(const BC& bc) const {

		return this->getBit_(bc);
	}

	/* TODO: Add description */
	inline uint8_t getByte(const BC& bc) const {

		return this->getByte_(bc);
	}

	/* TODO: Add description */
	inline BC copyTo(BufferWriter& buffer) const {

		return this->copyTo_(buffer);
	}

	/* TODO: Add description */
    BC copyTo(uint8_t* const bytes, size_t max) const;

	/* TODO: Add description */
	inline BC getLength() const {

		return this->getLength_();
	}

	/* TODO: Add description */
	inline bool isEmpty() const {

		return (this->getLength() == 0);
	}


	/* TODO: Add description */
	uint8_t getBytePadded(BC bc, bool padLeft = false) const;


	/* TODO: Add description */
	BufferWindowReader getWindow(BC offset = 0, BC length = -1) const;


	/* TODO: Add description */
	String toBitString(bool split = false, BC from = -1, BC len = -1) const;

	/* TODO: Add description */
	String toHexString(bool split = false, BC from = -1, BC len = -1, bool markMisaligned = false) const;

	/* TODO: Add description */
	std::string toBase64String() const;

	/* TODO: Add description */
	String toRawString(size_t cols = 16, BC from = -1, BC len = -1) const;

	/* TODO: Add description */
	String toCString(size_t cols = 16, BC from = -1, BC len = -1) const;


	/* TODO: Add description */
	size_t printBitDump(BC from = -1, BC len = -1) const;

	/* TODO: Add description */
	void printHexDump(size_t nCols = 16) const;

	/* TODO: Add description */
	std::string getHexDump(size_t nCols = 16) const;


	/* TODO: Add description */
	BC exportToFile(const std::string& filename) const;


	/* TODO: Add description */
	bool isEqualTo(const BufferReader& reader) const;


	/* TODO: Add description */
	bool operator==(const BufferReader& reader) const {

		return this->isEqualTo(reader);
	}


	/* TODO: Add description */
	virtual ~BufferReader();

};

#endif
