#include "OpaqueField.h"
#include "BufferReader.h"
#include "String_.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor OpaqueField::desc_(
		FieldDataUnit::typeDescriptor(), 0, "OpaqueField");


/*
 * ___________________________________________________________________________
 */
OpaqueField::OpaqueField() : FieldDataUnit() {
}


/*
 * ___________________________________________________________________________
 */
OpaqueField::OpaqueField(const BC& capacity) : FieldDataUnit(capacity) {
}


/*
 * ___________________________________________________________________________
 */
OpaqueField::OpaqueField(const BufferReader& reader, const BC& max)
		: FieldDataUnit() {

	this->dissector().dissectFromBuffer(reader, max);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& OpaqueField::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
bool OpaqueField::decode_(const BufferReader& reader) {

	return true;
}


/*
 * ___________________________________________________________________________
 */
bool OpaqueField::isDecoded_() const {

	return !this->dissector().isAccepting();
}


/*
 * ___________________________________________________________________________
 */
bool OpaqueField::encode_() {

	return true;
}


/*
 * ___________________________________________________________________________
 */
DataUnit* OpaqueField::newInstance_() const {

	return new OpaqueField(this->getCapacity());
}


/*
 * ___________________________________________________________________________
 */
OpaqueField::~OpaqueField() {
}

