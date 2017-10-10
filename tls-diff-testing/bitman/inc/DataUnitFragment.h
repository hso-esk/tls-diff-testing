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

#ifndef __DataUnitFragment_H__
#define __DataUnitFragment_H__

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "DataUnit.h"

class DataUnitStream;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DataUnitFragment : public DataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


	/* TODO: Add description */
	DataUnitStream& protocol_;

	/* TODO: Add description */
	BC offset_;

	/* TODO: Add description */
	BC len_;


protected:

	/* TODO: Add description */
	virtual void printBody(const PrintOptions& options) const;

	/* --- from DataUnit -> ProtocolDissector class: ----------------------- */

	/* TODO: Add description */
	virtual void dissectorBodyReset();

	/* TODO: Add description */
	virtual bool dissectorBodyIsAccepting() const;

	/* TODO: Add description */
	virtual BC dissectorBodyDissect(StreamReader& reader);

	/* --------------------------------------------------------------------- */

	/* --- from DataUnit -> BufferReader class: ---------------------------- */

	/* TODO: Add description */
	virtual bool getBit_(const BC& bc) const;

	/* TODO: Add description */
	virtual uint8_t getByte_(const BC& bc) const;

	/* TODO: Add description */
	virtual BC copyTo_(BufferWriter& buffer) const;

	/* TODO: Add description */
	virtual BC getLength_() const;

	/* --- from DataUnit class: -------------------------------------------- */

	/* TODO: Add description */
	virtual bool isDecoded_() const;

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual std::string	getAnchorBrackets_() const;


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	DataUnitFragment(DataUnitStream& protocol, const BC& size = -1);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;

	/* --- from DataUnit -> BufferWriter class: ---------------------------- */

	/* TODO: Add description */
	virtual bool appendBit(bool bit);

	/* TODO: Add description */
	virtual bool appendByte(uint8_t byte);

	/* --- from DataUnit -> BufferModifier class: -------------------------- */

	/* TODO: Add description */
	virtual bool setBit(const BC& bc, bool bit);

	/* TODO: Add description */
	virtual bool setByte(const BC& bc, uint8_t byte);

	/* TODO: Add description */
	virtual void clear();

	/* TODO: Add description */
	virtual void truncate(const BC& length);

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual ~DataUnitFragment();

};

#endif
