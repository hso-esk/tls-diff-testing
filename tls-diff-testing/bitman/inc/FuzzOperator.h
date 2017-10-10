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

#ifndef __FuzzOperator_H__
#define __FuzzOperator_H__

#include "DataUnitOperator.h"
#include "DecisionReader.h"

class DataUnit;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class FuzzOperator : public DataUnitOperator {

private:

	/* TODO: Add description */
	DecisionReader& decisionReader_;


protected:

	/* TODO: Add description */
	inline DecisionReader& getDecisionReader() {

		return decisionReader_;
	}


public:

	/* TODO: Add description */
	FuzzOperator(DecisionReader& decisionReader);


	/* TODO: Add description */
	virtual ~FuzzOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class FuzzIntOperator : public FuzzOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	FuzzIntOperator(DecisionReader& decisionReader);


	/* TODO: Add description */
	virtual const DataUnitFilter& getApplicationFilter() const;


	/* TODO: Add description */
	virtual ~FuzzIntOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class TruncationFuzzOperator : public FuzzOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	TruncationFuzzOperator(DecisionReader& decisionReader);


	/* TODO: Add description */
	virtual ~TruncationFuzzOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class RepairingFuzzOperator : public FuzzOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	RepairingFuzzOperator(DecisionReader& decisionReader);


	/* TODO: Add description */
	virtual ~RepairingFuzzOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class FuzzDataOperator : public FuzzOperator {

private:

	bool preserveLen_;


protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	FuzzDataOperator(DecisionReader& decisionReader, bool preserveLen = false);


	/* TODO: Add description */
	virtual const DataUnitFilter& getApplicationFilter() const;


	/* TODO: Add description */
	virtual ~FuzzDataOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class AppendingFuzzOperator : public FuzzOperator {

protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	AppendingFuzzOperator(DecisionReader& decisionReader);


	/* TODO: Add description */
	virtual const DataUnitFilter& getApplicationFilter() const;


	/* TODO: Add description */
	virtual ~AppendingFuzzOperator();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class GeneratingFuzzOperator : public FuzzOperator {

private:

	/* TODO: Add description */
    bool generate(DataUnit& du);


protected:

	/* TODO: Add description */
	bool apply_(DataUnitCursor& cursor, PropertyNode& log);


public:

	/* TODO: Add description */
	GeneratingFuzzOperator(DecisionReader& decisionReader);


	/* TODO: Add description */
	virtual ~GeneratingFuzzOperator();

};

#endif
