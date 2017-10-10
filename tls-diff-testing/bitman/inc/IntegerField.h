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

#ifndef __IntegerField_H__
#define __IntegerField_H__

#include <string>
#include <vector>
#include <inttypes.h>

#include "FieldDataUnit.h"


class IntegerField : public FieldDataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


protected:

	/* TODO: Add description */
	static size_t getBitWeight(size_t bit, size_t size,
    		bool bigEndianBytes_ = true, bool bigEndianBits_ = true);


	/* TODO: Add description */
    bool isSigned_;

    /* TODO: Add description */
    bool bigEndianBytes_;

    /* TODO: Add description */
    bool bigEndianBits_;

    /* TODO: Add description */
    int value_;

    /* TODO: Add description */
    bool decoded_;


	/* --- from PropertyNode class: ---------------------------------------- */

	/* TODO: Add description */
    virtual void propReadHook_(const std::string& name, DynamicValue& value) const;

	/* TODO: Add description */
	virtual void propWriteHook_(const std::string& name, DynamicValue& value);

	/* --- from FieldDataUnit class: --------------------------------------- */

	/* TODO: Add description */
	virtual bool decode_(const BufferReader& reader);

	/* TODO: Add description */
	virtual bool encode_();

	/* --- from DataUnit class: -------------------------------------------- */

	/* TODO: Add description */
	virtual bool isDecoded_() const;

	/* TODO: Add description */
	virtual DataUnit* newInstance_() const;

	/* --------------------------------------------------------------------- */

    /* TODO: Add description */
	virtual std::string getInfo_() const;


public:

    /* TODO: Add description */
	static IntegerField* newIntBE(size_t bitWidth);

    /* TODO: Add description */
	static IntegerField* newUIntBE(size_t bitWidth);

    /* TODO: Add description */
	static IntegerField* newIntLE(size_t bitWidth);

    /* TODO: Add description */
	static IntegerField* newUIntLE(size_t bitWidth);


	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: implement min / max */

    /* TODO: Add description */
    IntegerField(const BC& size, bool isSigned = false,
    		bool bigEndianBytes = true, bool bigEndianBits = true);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


    /* TODO: Add description */
	bool isSigned() const;


    /* TODO: Add description */
	template<typename T>
	T getValue() const;

    /* TODO: Add description */
	void setValue(int value);


    /* TODO: Add description */
	virtual ~IntegerField();

};

#endif
