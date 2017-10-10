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

#include "StreamReader.h"


/*
 * ___________________________________________________________________________
 */
StreamReader::StreamReader() : accu_(0) {
}


/*
 * ___________________________________________________________________________
 */
uint8_t StreamReader::readByte(bool remove) {

	uint8_t byte = this->readByte_(remove);
	if (remove) {
		++accu_;
	}
	return byte;
}


/*
 * ___________________________________________________________________________
 */
bool StreamReader::readBit(bool remove) {

	bool bit = this->readBit_(remove);
	if (remove) {
		accu_ <<= 1;
	}
	return bit;
}


/*
 * ___________________________________________________________________________
 */
BC StreamReader::flush(const BC& max) {

	BC len = BC::getMin(this->getLength(), max);
	BC ret = len;

	if (len.isDef()) {
		while (len >= 1) {
			this->readByte();
			len--;
		}
		while (len > 0) {
			this->readBit();
			len >>= 1;
		}
	} else {
		ret = 0;
	}

	return ret;
}


/*
 * ___________________________________________________________________________
 */
StreamReader::~StreamReader() {
}

