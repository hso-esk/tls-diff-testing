#include "StringField.h"
#include "BufferReader.h"
#include "String_.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor StringField::desc_(
		OpaqueField::typeDescriptor(), 0, "StringField");


/*
 * ___________________________________________________________________________
 */
StringField::StringField() : OpaqueField() {
}


/*
 * ___________________________________________________________________________
 */
StringField::StringField(const BC& capacity) : OpaqueField(capacity) {
}


/*
 * ___________________________________________________________________________
 */
StringField::StringField(const BufferReader& reader, const BC& max)
		: OpaqueField() {

	this->dissector().dissectFromBuffer(reader, max);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& StringField::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
DataUnit* StringField::newInstance_() const {

	return new StringField(this->getCapacity());
}


/*
 * ___________________________________________________________________________
 */
string StringField::getInfo_() const {

	uint8_t str[128];

	BC len = this->getBuffer().copyTo(str, sizeof(str) - 1);
	str[len.byte()] = 0;

	return String::format("\"%s\"", str);
}


/*
 * ___________________________________________________________________________
 */
StringField::~StringField() {
}

