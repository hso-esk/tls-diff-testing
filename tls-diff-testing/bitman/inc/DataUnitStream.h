#ifndef __Protocol_H__
#define __Protocol_H__

#include <vector>
#include "StreamVectorDataUnit.h"

class DataUnitFragment;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DataUnitStream : public StreamVectorDataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


	/* TODO: Add description */
	std::vector<DataUnitFragment*>	fragments_;


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	DataUnitStream(DataUnit* unit);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	DataUnitFragment* newFragment(const BC& size = -1);


	/* TODO: Add description */
	virtual ~DataUnitStream();

};

#endif
