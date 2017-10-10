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

#ifndef __DecisionReader_H__
#define __DecisionReader_H__

#include "StreamReader.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DecisionReader : public StreamReader {

private:

	/* TODO: Add description */
	StreamReader& streamer_;


protected:

	/* --- from StreamReader class: ---------------------------------------- */

	/* TODO: Add description */
	inline uint8_t readByte_(bool remove = true) {

		return streamer_.readByte(remove);
	}

	/* TODO: Add description */
	inline bool readBit_(bool remove = true) {

		return streamer_.readBit(remove);
	}

	/* --- from StreamReader -> BufferReader class: ------------------------ */

	/* TODO: Add description */
	inline bool getBit_(const BC& bc) const {

		return streamer_.getBit(bc);
	}

	/* TODO: Add description */
	inline uint8_t getByte_(const BC& bc) const {

		return streamer_.getByte(bc);
	}

	/* TODO: Add description */
	inline BC copyTo_(BufferWriter& buffer) const {

		return streamer_.copyTo(buffer);
	}

	/* TODO: Add description */
	inline BC getLength_() const {

		return streamer_.getLength();
	}

	/* --------------------------------------------------------------------- */


public:

	/* TODO: Add description */
	DecisionReader(StreamReader& streamer);


	inline StreamReader& getStreamReader() {

		return streamer_;
	}


	/* TODO: Add description */
	bool readBoolUniform();

	/* TODO: Add description */
	size_t	readUIntUniform(size_t max);

	/* TODO: Add description */
	size_t	readUIntExponential(size_t num, size_t denom);


	/* TODO: Add description */
	virtual ~DecisionReader();

};

#endif
