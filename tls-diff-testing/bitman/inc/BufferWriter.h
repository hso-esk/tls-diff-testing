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

#ifndef __BufferWriter_H__
#define __BufferWriter_H__

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "BC.h"

class String;
class BufferReader;
class StreamReader;


/* ==========================================================================
 *
 * Inheriting classes need to implement:
 *
 *
 * ========================================================================== */

class BufferWriter {

private:

	/* TODO: Add description */
	static int convertDigit(char c, size_t base);


public:

	/* TODO: Add description */
	BufferWriter();

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual bool appendBit(bool bit) = 0;

	/* TODO: Add description */
	virtual bool appendByte(uint8_t byte) = 0;

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	BC appendBits(const bool* const bits, size_t max);

	/* TODO: Add description */
	BC appendBytes(const uint8_t* const bytes, size_t max);

	/* TODO: Add description */
	BC appendFromBuffer(const BufferReader& reader, BC max = -1);

	/* TODO: Add description */
	BC appendFromString(const std::string& str, BC max = -1);

	/* TODO: Add description */
	BC appendFromBitString(const std::string& str, const BC& max = -1);

	/* TODO: Add description */
	BC appendFromHexString(const std::string& str, const BC& max = -1);

	/* TODO: Add description */
	BC appendFromBase64String(const std::string& str, const BC& max = -1);

	/* TODO: Add description */
	BC appendFromAsciiString(const std::string& str, const BC& max = -1);

	/* TODO: Add description */
	BC appendFromFile(const std::string& filename);

	/* TODO: Add description */
	BC appendFromHexFile(const std::string& filename);


	/* TODO: Add description */
	BC consumeStream(StreamReader& reader, BC max = -1);

	/* TODO: Add description */
	BC consumeBitString(std::string& str, BC max = -1);

	/* TODO: Add description */
	BC consumeHexString(std::string& str, BC max = -1);

	/* TODO: Add description */
	BC consumeBase64String(std::string& str, BC max = -1);

	/* TODO: Add description */
	BC consumeAsciiString(std::string& str, BC max = -1);


	/* TODO: Add description */
	BufferWriter& operator<<(const std::string& str);


	/* TODO: Add description */
	BC appendNumberBits(size_t number, size_t nBits,
			bool bigEndian = true, BC max = -1);

	/* TODO: Add description */
	BC appendDigitBits(char c, size_t base, bool bigEndian = true, BC max = -1);


	/* TODO: Add description */
	virtual ~BufferWriter();

};

#endif
