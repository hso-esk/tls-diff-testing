#ifndef __DataUnitConverter_H__
#define __DataUnitConverter_H__

#include "DataUnit.h"


/* =========================================================================
 *
 *
 *
 * ========================================================================= */

class DataUnitConverter {

private:

	const DataUnit& dataUnit_;

    /* TODO: Add description */
	std::string getAsJSON_(const DataUnit& dataUnit) const;


public:

    /* TODO: Add description */
	DataUnitConverter(const DataUnit& dataUnit);


    /* TODO: Add description */
	std::string getAsJSON() const;


    /* TODO: Add description */
	virtual ~DataUnitConverter();

};

#endif
