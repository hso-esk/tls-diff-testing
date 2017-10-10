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
