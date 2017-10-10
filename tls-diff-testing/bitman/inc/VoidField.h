#ifndef __VoidField_H__
#define __VoidField_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "FieldDataUnit.h"

class BC;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class VoidField : public FieldDataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


protected:

	/* --- from FieldDataUnit class: --------------------------------------- */

	/* TODO: Add description */
	virtual bool decode_(const BufferReader& reader);

	/* TODO: Add description */
	virtual bool encode_();

	/* --- from DataUnit class: -------------------------------------------- */

	/* TODO: Add description */
	virtual bool isDecoded_() const;

	/* TODO: Add description */
	virtual DataUnit* newInstance_() const;

	/* --------------------------------------------------------------------- */


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	VoidField();


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	virtual ~VoidField();

};

#endif
