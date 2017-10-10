#ifndef __DataUnitVisitor_H__
#define __DataUnitVisitor_H__

#include <stdlib.h>

class DataUnit;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DataUnitVisitor {

private:

	/* TODO: Add description */
	size_t visit(DataUnit& dataUnit, size_t index, size_t depth);


protected:

	/* TODO: Add description */
	virtual bool visiting(DataUnit& dataUnit, size_t index, size_t depth) = 0;


public:

	/* TODO: Add description */
	DataUnitVisitor();

	/* TODO: Add description */
	size_t visit(DataUnit& dataUnit);

	/* TODO: Add description */
	virtual ~DataUnitVisitor();

};

#endif
