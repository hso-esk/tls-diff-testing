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

#ifndef __StreamReader_H__
#define __StreamReader_H__

#include "BufferReader.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class StreamReader : public BufferReader {

private:

	/* TODO: Add description */
	BC accu_;


protected:

	/* === To be implemented by sub-classes: =============================== */

	/* TODO: Add description */
	virtual uint8_t readByte_(bool remove = true) = 0;

	/* TODO: Add description */
	virtual bool readBit_(bool remove = true) = 0;

	/* ===================================================================== */


public:

	/* TODO: Add description */
	StreamReader();

	/* TODO: Add description */
	uint8_t readByte(bool remove = true);

	/* TODO: Add description */
	bool readBit(bool remove = true);


	/* TODO: Add description */
	BC flush(const BC& max = -1);


	/* TODO: Add description */
	inline const BC& getAccumulator() const {

		return accu_;
	}

	/* TODO: Add description */
	inline void resetAccumulator() {

		accu_ = 0;
	}

	virtual ~StreamReader();

};

#endif
