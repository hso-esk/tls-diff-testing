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
