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

#ifndef __DataUnitOperators_H__
#define __DataUnitOperators_H__

#include "PropertyNode.h"

class DataUnitCursor;
class DataUnitFilter;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DataUnitOperator {

private:

	/* TODO: Add description */
	PropertyNode lastOpLog_;


protected:

	/* TODO: Add description */
	virtual bool apply_(DataUnitCursor& cursor, PropertyNode& log) = 0;


public:

	/* TODO: Add description */
	DataUnitOperator();


	/* TODO: Add description */
	bool apply(DataUnitCursor& cursor);


	/* TODO: Add description */
	virtual const DataUnitFilter& getApplicationFilter() const;


	/* TODO: Add description */
	inline PropertyNode& getLastOperationLog() {

		return lastOpLog_;
	}


	/* TODO: Add description */
	virtual ~DataUnitOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class VoidingOperator : public DataUnitOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	VoidingOperator();


	/* TODO: Add description */
	virtual ~VoidingOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class OpacifyingOperator : public DataUnitOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	OpacifyingOperator();


	/* TODO: Add description */
	virtual const DataUnitFilter& getApplicationFilter() const;


	/* TODO: Add description */
	virtual ~OpacifyingOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DuplicatingOperator : public DataUnitOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	DuplicatingOperator();


	/* TODO: Add description */
	virtual ~DuplicatingOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DeletingOperator : public DataUnitOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	DeletingOperator();


	/* TODO: Add description */
	virtual ~DeletingOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class RepairingOperator : public DataUnitOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	RepairingOperator();


	/* TODO: Add description */
	virtual ~RepairingOperator();

};


#endif
