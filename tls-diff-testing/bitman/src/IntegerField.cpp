#include <stdexcept>
#include "IntegerField.h"
#include "String_.h"
#include "Value.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor IntegerField::desc_(
		FieldDataUnit::typeDescriptor(), 0, "IntegerField");


/*
 * ___________________________________________________________________________
 */
IntegerField* IntegerField::newIntBE(size_t bitWidth) {

	return new IntegerField(BC(0, bitWidth), true, true);
}


/*
 * ___________________________________________________________________________
 */
IntegerField* IntegerField::newUIntBE(size_t bitWidth) {

	return new IntegerField(BC(0, bitWidth), false, true);
}


/*
 * ___________________________________________________________________________
 */
IntegerField* IntegerField::newIntLE(size_t bitWidth) {

	return new IntegerField(BC(0, bitWidth), true, false);
}


/*
 * ___________________________________________________________________________
 */
IntegerField* IntegerField::newUIntLE(size_t bitWidth) {

	return new IntegerField(BC(0, bitWidth), false, false);
}


/*
 * ___________________________________________________________________________
 */
IntegerField::IntegerField(const BC& size,
		bool isSigned, bool bigEndianBytes,	bool bigEndianBits)
		: FieldDataUnit(size) {

	isSigned_		= isSigned;
	bigEndianBytes_	= bigEndianBytes;
	bigEndianBits_	= bigEndianBits;

	value_ = 0;
	decoded_ = false;

	String name;
	name.appendBool(isSigned_, "", "u");
	name.appendFormat("int%d", size.bit());
	this->setName(name);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& IntegerField::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 *
 *  (18 17 16) - 15 14 13 12 11 10 09 08 - 07 06 05 04 03 02 01 00
 *	             07 06 05 04 03 02 01 00 - 15 14 13 12 11 10 09 08 - (18 17 16)
 *
 *	(16 17 18) - 08 09 10 11 12 13 14 15 - 00 01 02 03 04 05 06 07
 *	             00 01 02 03 04 05 06 07 - 08 09 10 11 12 13 14 15 - (16 17 18)
 *
 * ___________________________________________________________________________
 */
size_t IntegerField::getBitWeight(size_t bit, size_t size,
		bool bigEndianBytes_, bool bigEndianBits_) {


	size_t weight = 0;

	if (bigEndianBits_ == bigEndianBytes_) {
		if (bigEndianBytes_) {
			bit = size - bit - 1;
		}
		weight = bit;

	} else if (bigEndianBits_ && !bigEndianBytes_) {
		size_t n1 = bit % 8;
		size_t n8 = bit - n1;
		weight = n8 + ((size - n8 >= 8 ? 8 : size - n8) - n1) - 1;

	} else if (!bigEndianBits_ && bigEndianBytes_) {
		bit = size - bit - 1;
		size_t n1 = bit % 8;
		size_t n8 = bit - n1;
		weight = n8 + (7 - n1 >= size - n8 ? size - n8 - n1 - 1 : 7 - n1);

	}

	return weight;
}


/*
 * ___________________________________________________________________________
 */
DataUnit* IntegerField::newInstance_() const {

	return new IntegerField(this->getCapacity(),
			isSigned_, bigEndianBytes_, bigEndianBits_);
}


/*
 * ___________________________________________________________________________
 */
bool IntegerField::decode_(const BufferReader& reader) {

	BC size = this->getCapacity();

	int value = 0;

	BC bc = 0;
	while (bc < size) {
		size_t w = getBitWeight(bc.bit(), size.bit(),
				bigEndianBytes_, bigEndianBits_);
		if (w == (size.bit() - 1) && isSigned_) {
			/* TODO: handle sign bit */
		} else {
			if (reader.getBit(bc)) {
				value += (1 << w);
			}
		}
		bc <<= 1;
	}

	decoded_ = true;
	value_ = value;

	return decoded_;
}


/*
 * ___________________________________________________________________________
 */
bool IntegerField::isDecoded_() const {

	return decoded_;
}


/*
 * ___________________________________________________________________________
 */
bool IntegerField::encode_() {

	if (decoded_) {

		this->clearBuffer();

		BC bc = 0;
		BC size = this->getCapacity();
		while (bc < size) {
			size_t w = getBitWeight(bc.bit(), size.bit(),
					bigEndianBytes_, bigEndianBits_);
			if (isSigned_) {
				/* TODO: handle sign bit */
			} else {
				this->appendBit(((unsigned int)value_ & (1 << w)) != 0);
			}
			bc <<= 1;
		}
	}

	return decoded_;
}


/*
 * ___________________________________________________________________________
 */
string IntegerField::getInfo_() const {

	String info;
	if (decoded_) {
		info.appendFormat("%d", this->getValue<int>());
	}
	return info;
}


/*
 * ___________________________________________________________________________
 */
bool IntegerField::isSigned() const {

	return isSigned_;
}


/*
 * ___________________________________________________________________________
 */
template<typename T>
T IntegerField::getValue() const {

	if (decoded_) {
		return (T)value_;
	} else {
		throw std::runtime_error(
				"IntegerField::getValue(): No decoded value available");
	}
}

template int IntegerField::getValue<int>() const;

template unsigned int IntegerField::getValue<unsigned int>() const;


/*
 * ___________________________________________________________________________
 */
void IntegerField::setValue(int value) {

	value_ = value;
	decoded_ = true;
	this->encode();
}


/*
 * ___________________________________________________________________________
 */
void IntegerField::propReadHook_(
		const string& name, DynamicValue& value) const {

	if (name == ".value" && this->isDecoded()) {
		value.setValue<int>(this->getValue<int>());
	} else {
		/* process base class hook */
		FieldDataUnit::propReadHook_(name, value);
	}
}


/*
 * ___________________________________________________________________________
 */
void IntegerField::propWriteHook_(const string& name, DynamicValue& value) {

	if (name == ".value") {
		/* capture the value */
		this->setValue(value.getValue<int>());
		value.setUndef();
	} else if (name == ".value_add") {
		/* capture the value */
		this->setValue(this->getValue<int>() + value.getValue<int>());
		value.setUndef();
	} else if (name == ".value_sub") {
		/* capture the value */
		this->setValue(this->getValue<int>() - value.getValue<int>());
		value.setUndef();
	} else {
		/* process base class hook */
		FieldDataUnit::propWriteHook_(name, value);
	}
}


/*
 * ___________________________________________________________________________
 */
IntegerField::~IntegerField() {
}

