#ifndef __VectorDataUnit_H__
#define __VectorDataUnit_H__

#include "CompositeDataUnit.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class VectorDataUnit : public CompositeDataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


	/* TODO: Add description */
	DataUnit* template_;


protected:

	/* TODO: Add description */
	VectorDataUnit(bool empty);


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	VectorDataUnit();

	/* TODO: Add description */
	VectorDataUnit(DataUnit* elementTemplate);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	void setElementTemplate(DataUnit* elementTemplate);

	/* TODO: Add description */
	DataUnit* getElementTemplate() const;


	/* TODO: Add description */
	virtual ~VectorDataUnit();

};

#endif
