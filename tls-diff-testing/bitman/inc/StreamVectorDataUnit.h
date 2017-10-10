#ifndef __StreamVectorDataUnit_H__
#define __StreamVectorDataUnit_H__

#include "VectorDataUnit.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class StreamVectorDataUnit : public VectorDataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


	/* TODO: Add description */
	BC N_;


protected:

	/* --- from CompositeDataUnit class: ----------------------------------- */

	/* TODO: Add description */
	virtual bool expand_(size_t len, size_t decoded, bool dry, bool ahead);

	/* --- from DataUnit class: -------------------------------------------- */

	/* TODO: Add description */
	virtual DataUnit* newInstance_() const;

	/* --------------------------------------------------------------------- */


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	StreamVectorDataUnit();

	/* TODO: Add description */
	StreamVectorDataUnit(const BC& N);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	virtual ~StreamVectorDataUnit();

};

#endif
