#include "VoidField.h"


/*
 * ___________________________________________________________________________
 */
TypeDescriptor VoidField::desc_(
		FieldDataUnit::typeDescriptor(), 0, "VoidField");


/*
 * ___________________________________________________________________________
 */
VoidField::VoidField() : FieldDataUnit(0) {

	this->setName("void");
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& VoidField::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
bool VoidField::decode_(const BufferReader& reader) {

	/* there is nothing to do for a void field */
	return true;
}


/*
 * ___________________________________________________________________________
 */
bool VoidField::encode_() {

	/* there is nothing to do for a void field */
	return true;
}


/*
 * ___________________________________________________________________________
 */
bool VoidField::isDecoded_() const {

	return !this->dissector().isAccepting();
}


/*
 * ___________________________________________________________________________
 */
DataUnit* VoidField::newInstance_() const {

	return new VoidField();
}


/*
 * ___________________________________________________________________________
 */
VoidField::~VoidField() {
}

