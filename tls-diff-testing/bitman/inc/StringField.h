#ifndef __StringField_H__
#define __StringField_H__

#include <stdlib.h>
#include <string.h>
#include "OpaqueField.h"

class BufferReader;


/* ==========================================================================
 *
 *	TODO: Let StringField replace FieldDataUnit class?
 *
 * ========================================================================== */

class StringField : public OpaqueField {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


protected:

	/* --- from DataUnit class: -------------------------------------------- */

    /* TODO: Add description */
	virtual std::string getInfo_() const;

	/* TODO: Add description */
	virtual DataUnit* newInstance_() const;

	/* --------------------------------------------------------------------- */


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	StringField();

	/* TODO: Add description */
	StringField(const BC& capacity);

	/* TODO: Add description */
	StringField(const BufferReader& reader, const BC& max = -1);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	virtual ~StringField();

};

#endif
