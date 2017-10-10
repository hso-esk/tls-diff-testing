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

#ifndef __ProtocolDissector_H__
#define __ProtocolDissector_H__

#include <stdexcept>
#include "BC.h"
#include "StreamStreamReader.h"

class BufferReader;
class StreamReader;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DissectionError : public std::runtime_error {

public:

	DissectionError(const std::string& error) : std::runtime_error(error) {
	}

};


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DissectorBody {

public:

	/* TODO: Add description */
	virtual void dissectorBodyReset() = 0;

	/* TODO: Add description */
	virtual bool dissectorBodyIsAccepting() const = 0;

	/* TODO: Add description */
	virtual BC dissectorBodyDissect(StreamReader& reader) = 0;

};


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class Dissector {

private:

	/* the dissector body */
	DissectorBody& body_;

	/* the externally defined size of the dissector */
	BC size_;

	/* the total amount of data consumed by the dissector */
	BC length_;

	/* the amount of overflow data discarded by the dissector */
	BC overflow_;

	/* true if dissector has been closed */
	bool closed_;

	/* TODO: Add description */
	StreamStreamReader* reader_;


public:

	/* TODO: Add description */
	Dissector(DissectorBody& body);


	/* TODO: Add description */
	BC reset();

	/* TODO: Add description */
	BC reset(const BC& size);


	/* TODO: Add description */
	inline void close() {

		closed_ = true;
	}


	/* TODO: Add description */
	void setSize(const BC& size);

	/* TODO: Add description */
	inline const BC& getSize() const {

		return size_;
	}


	/* TODO: Add description */
	inline BC getLength() const {

		return length_ + ((reader_ != 0) ? reader_->getAccumulator() : 0);
	}

	/* TODO: Add description */
	inline BC getAcceptance() const {

		/* returns an undefined value if size_ is undefined */
		return closed_ ? 0 : size_ - this->getLength();
	}


	/* TODO: Add description */
	bool isAccepting() const;


	/* TODO: Add description */
	inline BC getOverflow() const {

		return overflow_;
	}

	/* TODO: Add description */
	inline bool hasOverflow() const {

		/* excess_ is never undefined */
		return overflow_ > 0;
	}

	/* TODO: Add description */
	inline bool hasUnderflow() const {

        /* TODO: use just "body_.dissectorBodyIsAccepting()"? */
		return this->getAcceptance() == 0 && body_.dissectorBodyIsAccepting();
	}


	/* TODO: Add description */
	BC dissect(StreamReader& reader, const BC& max = -1);

	/* TODO: Add description */
	BC dissectFromBuffer(const BufferReader& reader, const BC& max = -1);


	/* TODO: Add description */
	virtual ~Dissector();

};

#endif
