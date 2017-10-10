#ifndef __StaticVectorDataUnit_H__
#define __StaticVectorDataUnit_H__

#include "VectorDataUnit.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class StaticVectorDataUnit : public VectorDataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


	/* TODO: Add description */
	size_t N_;


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
	StaticVectorDataUnit(size_t N);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	virtual ~StaticVectorDataUnit();

};

#endif
