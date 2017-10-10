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

#include <iostream>
#include <fstream>
#include <ios>
#include "BufferStreamReader.h"
#include "StreamReader.h"
#include "String_.h"
#include "BufferWriter.h"

using namespace std;


/*
 * ___________________________________________________________________________
 */
int BufferWriter::convertDigit(char c, size_t base) {

	string digits;
	if (base <= 16) {
		digits = "0123456789ABCDEF";
		if (c >= 'a' && c <= 'z') {
			/* treat lower case letters as upper case letters */
			c -= 'a' - 'A';
		}
	} else if (base == 64) {
		digits = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz0123456789+/";
	}

	size_t val = digits.find(c);
	if (val != string::npos && val >= base) {
		val = -1;
	}

	return val;
}


/*
 * ___________________________________________________________________________
 */
BufferWriter::BufferWriter() {
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendBits(const bool* const bits, size_t max) {

	BC len = 0;
	bool stop = (bits == 0);
	for (size_t i = 0; !stop && i < max; i++) {
		if (this->appendBit(bits[i])) {
			len <<= 1;
		} else {
			stop = true;
		}
	}
	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendBytes(const uint8_t* const bytes, size_t max) {

	BC len = 0;
	bool stop = (bytes == 0);
	for (size_t i = 0; !stop && i < max; i++) {
		if (this->appendByte(bytes[i])) {
			len++;
		} else {
			stop = true;
		}
	}
	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendFromString(const string& str, BC max) {

	BC len = 0;

	String stream(str);
	bool stop = false;

	while (stream.length() > 0 && !stop && (max.isUndef() || len < max)) {

		size_t strLen = stream.length();

		stream.removeLeadingWhitespaces();

		if (stream.removeLeadingText("0b")
				|| stream.removeLeadingText("0B")) {

			len += this->consumeBitString(stream);

		} else {

			stream.removeLeadingText("0x");
			stream.removeLeadingText("0X");

			len += this->consumeHexString(stream);
		}

		/* stop if nothing has been consumed from string */
		if (stream.length() == strLen) {
			stop = true;
		}
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
BufferWriter& BufferWriter::operator<<(const string& str) {

	this->appendFromString(str);
	return *this;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendFromBuffer(const BufferReader& reader, BC max) {

	BufferStreamReader reader_(reader);
	return this->consumeStream(reader_, max);
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::consumeStream(StreamReader& reader, BC max) {

	BC len = BC::getMin(reader.getLength(), max);

	/* consume bytes ... */
	BC bc = 0;
	bool stop = false;
	while (!stop && (len.isUndef() || ((bc + 1) <= len))) {
		if (this->appendByte(reader.readByte(false))) {
			reader.readByte();
			bc++;
		} else {
			stop = true;
		}
	}

	/* consume remaining bits ... */
	stop = false;
	while (!stop && bc < len) {
		if (this->appendBit(reader.readBit(false))) {
			reader.readBit();
			bc <<= 1;
		} else {
			stop = true;
		}
	}

	return bc;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendFromFile(const string& filename) {

	/* the number of bytes read from the file */
	BC len = 0;

	/* open the file to read from in binary mode */
	std::ifstream ifs(filename.data());
	if (ifs.is_open()) {
		char c;
		bool stop = false;
		while (!stop && ifs.get(c)) {
			if (this->appendByte((uint8_t)c)) {
				len++;
			} else {
				stop = true;
			}
		}
		ifs.close();
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendFromHexFile(const string& filename) {

	/* the number of bytes read from the file */
	BC len = 0;

	/* open the file to read from in binary mode */
	std::ifstream ifs(filename.data());
	if (ifs.is_open()) {
		string line;
		while (getline(ifs, line)) {
			/* ignore lines starting with '#' or '@' */
			if (line.find_first_of("#@") != 0) {
				bool stop = false;
				while (!stop && line.length() > 0) {
					len += this->consumeHexString(line);
					if (line.find_first_of(" \t") != 0) {
						stop = true;
					} else {
						line.erase(0, 1);
					}
				}
			}
		}
		ifs.close();
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendFromAsciiString(const string& str, const BC& max) {

	String stream(str);
	return this->consumeAsciiString(stream, max);
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendFromBitString(const string& str, const BC& max) {

	String stream(str);
	return this->consumeBitString(stream, max);
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendFromHexString(const string& str, const BC& max) {

	String stream(str);
	return this->consumeHexString(stream, max);
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendFromBase64String(const string& str, const BC& max) {

	String stream(str);
	return this->consumeBase64String(stream, max);
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::consumeBitString(string& str, BC max) {

	BC len = 0;
	String stream(str);
	size_t n = stream.countLeading("01");

	for (size_t i = 0; (i < n) && (max.isUndef() || len < max); i++) {
		len += this->appendDigitBits(stream[i], 2);
	}
	/* TODO: do not erase more than consumed (if max is defined) */
	str.erase(0, n);

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::consumeHexString(string& str, BC max) {

	BC len = 0;
	String stream(str);
	size_t n = stream.countLeading("0123456789abcdefABCDEF");

	for (size_t i = 0; (i < n) && (max.isUndef() || (len << 4) <= max); i++) {
		len += this->appendDigitBits(stream[i], 16);
	}
	/* TODO: do not erase more than consumed (if max is defined) */
	str.erase(0, n);

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::consumeBase64String(string& str, BC max) {

	BC len = 0;
	String stream(str);
	size_t n = stream.countLeading("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz0123456789+/");

	size_t nFullDigits = n - (n % 4);
	size_t nRemBits = 0;
	if ((n % 4) == 2) {
		nFullDigits += 1;
		nRemBits = 2;
	} else if ((n % 4) == 3) {
		nFullDigits += 2;
		nRemBits = 4;
	}

	for (size_t i = 0; (i < nFullDigits) &&
			(max.isUndef() || (len << 6) <= max); ++i) {
		len += this->appendDigitBits(stream[i], 64);
	}

	/* add remaining bits */
	len += this->appendDigitBits(
			stream[nFullDigits], 64, true, BC(0, nRemBits));

	/* TODO: do not erase more than consumed (if max is defined) */
	str.erase(0, n);

	/* remove padding character */
	size_t npad = stream.countLeading("=");
	/* TODO: sanitize padding */
	str.erase(0, npad);

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::consumeAsciiString(string& str, BC max) {

	BC len = 0;
	size_t n = str.length();
	String stream(str);

	for (size_t i = 0; (i < n) && (max.isUndef() || len < max); i++) {
		len += this->appendByte(uint8_t(stream.at(i)));
	}
	str.erase(0, n);

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendNumberBits(
		size_t number, size_t nBits, bool bigEndian, BC max) {

	BC len = 0;
	size_t mask = bigEndian ? ((size_t)1 << (nBits - 1)) : 1;

	for (; (nBits > 0) && (max.isUndef() || (len << 1) <= max); nBits--) {
		if (this->appendBit((number & mask) != 0)) {
			len <<= 1;
		}
		if (bigEndian) {
			mask >>= 1;
		} else {
			mask <<= 1;
		}
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC BufferWriter::appendDigitBits(char c, size_t base, bool bigEndian, BC max) {

	BC len = 0;
	size_t nBits = 1;
	int digit = convertDigit(c, base);

	if (digit >= 0) {
		while (((size_t)1 << nBits) < base) {
			nBits++;
		}
		len = this->appendNumberBits(digit, nBits, bigEndian, max);
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
BufferWriter::~BufferWriter() {
}

