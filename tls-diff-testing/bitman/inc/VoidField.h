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

#ifndef __VoidField_H__
#define __VoidField_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "FieldDataUnit.h"

class BC;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class VoidField : public FieldDataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


protected:

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


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	VoidField();


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	virtual ~VoidField();

};

#endif
