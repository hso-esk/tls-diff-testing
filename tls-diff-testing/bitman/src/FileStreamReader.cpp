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
#include "FileStreamReader.h"

using std::vector;
using std::string;
using std::ifstream;


/*
 * ___________________________________________________________________________
 */
FileStreamReader::FileStreamReader(const string& filename, bool infinite) :
		filename_(filename), length_(-1) {

	/* open the file to read from in binary mode */
	ifs_ = new ifstream(filename_.data());
	if (!ifs_->is_open()) {
		ifs_->close();
		ifs_ = (ifstream*)0;
		length_ = 0;
	} else if (!infinite) {
		std::streampos fsize = ifs_->tellg();
		ifs_->seekg(0, std::ios::end);
		length_ = BC(ifs_->tellg() - fsize, 0);
		ifs_->seekg(0, std::ios::beg);
	}
}


/*
 * ___________________________________________________________________________
 */
void FileStreamReader::read_() {

	char c;
	if (ifs_ != 0 && ifs_->is_open() && ifs_->get(c)) {
		buffer_.appendByte((uint8_t)c);
	}
}


/*
 * ___________________________________________________________________________
 */
uint8_t FileStreamReader::readByte_(bool remove) {

	if (buffer_.getLength() < 1) {
		this->read_();
	}
	if (buffer_.getLength() >= 1 && (length_.isUndef() || length_ >= 1)) {
		if (remove) {
			length_--;
		}
		return buffer_.readByte(remove);
	} else {
		throw std::runtime_error(
				"FileStreamReader::readByte(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
bool FileStreamReader::readBit_(bool remove) {

	if (buffer_.getLength() == 0) {
		this->read_();
	}
	if (buffer_.getLength() > 0 && (length_.isUndef() || length_ > 0)) {
		if (remove) {
			length_ <<= 1;
		}
		return buffer_.readBit(remove);
	} else {
		throw std::runtime_error(
				"FileStreamReader::readBit(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
bool FileStreamReader::getBit_(const BC& bc) const {

	throw std::runtime_error(
			"FileStreamReader::getBit(...): Not yet implemented");
}


/*
 * ___________________________________________________________________________
 */
uint8_t	FileStreamReader::getByte_(const BC& bc) const {

	throw std::runtime_error(
			"FileStreamReader::getByte(...): Not yet implemented");
}


/*
 * ___________________________________________________________________________
 */
BC FileStreamReader::copyTo_(BufferWriter& buffer) const {

	return BC::undef();
}


/*
 * ___________________________________________________________________________
 */
BC FileStreamReader::getLength_() const {

	return length_;
}


/*
 * ___________________________________________________________________________
 */
FileStreamReader::~FileStreamReader() {

	if (ifs_ != 0) {
		ifs_->close();
		delete ifs_;
	}
}
