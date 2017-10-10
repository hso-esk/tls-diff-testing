#ifndef __OpaqueField_H__
#define __OpaqueField_H__

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "FieldDataUnit.h"

class BufferReader;


/* ==========================================================================
 *
 *	TODO: Let OpaqueField replace FieldDataUnit class?
 *
 * ========================================================================== */

class OpaqueField : public FieldDataUnit {

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
	OpaqueField();

	/* TODO: Add description */
	OpaqueField(const BC& capacity);

	/* TODO: Add description */
	OpaqueField(const BufferReader& reader, const BC& max = -1);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	virtual ~OpaqueField();

};

#endif
