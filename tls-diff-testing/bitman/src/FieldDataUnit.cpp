#include <FieldDataUnit.h>
#include <iostream>
#include "String_.h"
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::string;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor FieldDataUnit::desc_(
		DataUnit::typeDescriptor(), 0, "FieldDataUnit");


/*
 * ___________________________________________________________________________
 */
FieldDataUnit::FieldDataUnit() : DataUnit(), buffer_() {
}


/*
 * ___________________________________________________________________________
 */
FieldDataUnit::FieldDataUnit(const BC& capacity) :
		DataUnit(), buffer_(capacity) {

    /* TODO: do we really need this? */
	this->dissector().setSize(capacity);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& FieldDataUnit::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
void FieldDataUnit::printBody(const PrintOptions& options) const {

	bool first = true;

	String pref(options.prefix);
	pref.setWidth(50);

	BC pos = 0;
	BC len = buffer_.getLength();
	while (pos == 0 || pos < len) {
		String hex = buffer_.toHexString(true, pos, 8, true);
		if (options.from.isDef() && options.from > pos) {
			for (size_t i = 0; i < 8 && i < (options.from - pos).byte(); i++) {
				if (hex.length() > 3*i) {
					hex.at(3*i) = '-';
					hex.at(3*i + 1) = '-';

				}
			}
		}
		hex.setWidth(23);
		if (!first) {
			cout << endl << pref;
		}
		cout << "| " << String::makeBoldRed(hex) << " |";
		first = false;
		pos += 8;
	}

	DataUnit::printBody(options);
}


/*
 * ___________________________________________________________________________
 */
string FieldDataUnit::getAsText() const {

	String text;
	text.appendFormat("%s(\"%s\", %s of %s) [ %s ] <%s>",
			this->getTypeName().c_str(), this->getRefName().c_str(),
			this->getLength().toString().c_str(),
			this->dissector().getSize().toString().c_str(),
			this->toHexString(true).c_str(),
			this->getInfo_().c_str());
	return text;
}


/*
 * ___________________________________________________________________________
 */
void FieldDataUnit::dissectorBodyReset() {

	/* clear the buffer to accept new data */
	buffer_.clear();
}


/*
 * ___________________________________________________________________________
 */
bool FieldDataUnit::dissectorBodyIsAccepting() const {

	BC remCap = buffer_.getRemainingCapacity();
	return remCap.isUndef() || remCap > 0;
}


/*
 * ___________________________________________________________________________
 */
BC FieldDataUnit::dissectorBodyDissect(StreamReader& reader) {

	BC len = buffer_.consumeStream(reader);

	if (buffer_.getCapacity() == buffer_.getLength()) {
		/* trigger decoding once raw data buffer has been filled */
		this->decode_(buffer_);
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
bool FieldDataUnit::encode() {

	return this->encode_();
}


/*
 * ___________________________________________________________________________
 */
bool FieldDataUnit::getBit_(const BC& bc) const {

	return buffer_.getBit(bc);
}


/*
 * ___________________________________________________________________________
 */
uint8_t	FieldDataUnit::getByte_(const BC& bc) const {

	return buffer_.getByte(bc);
}


/*
 * ___________________________________________________________________________
 */
BC FieldDataUnit::copyTo_(BufferWriter& buffer) const {

	return buffer_.copyTo(buffer);
}


/*
 * ___________________________________________________________________________
 */
BC FieldDataUnit::getLength_() const {

	return buffer_.getLength();
}


/*
 * ___________________________________________________________________________
 */
bool FieldDataUnit::appendBit(bool bit) {

	return buffer_.appendBit(bit);
}


/*
 * ___________________________________________________________________________
 */
bool FieldDataUnit::appendByte(uint8_t byte) {

	return buffer_.appendByte(byte);
}


/*
 * ___________________________________________________________________________
 */
bool FieldDataUnit::setBit(const BC& bc, bool bit) {

	return buffer_.setBit(bc, bit);
}


/*
 * ___________________________________________________________________________
 */
bool FieldDataUnit::setByte(const BC& bc, uint8_t byte) {

	return buffer_.setByte(bc, byte);
}


/*
 * ___________________________________________________________________________
 */
void FieldDataUnit::clear() {

	buffer_.clear();
}


/*
 * ___________________________________________________________________________
 */
void FieldDataUnit::truncate(const BC& length) {

	buffer_.truncate(length);
}


/*
 * ___________________________________________________________________________
 */
void FieldDataUnit::clearBuffer() {

	buffer_.clear();
}


/*
 * ___________________________________________________________________________
 */
BC FieldDataUnit::getCapacity() const {

	return buffer_.getCapacity();
}


/*
 * ___________________________________________________________________________
 */
FieldDataUnit::~FieldDataUnit() {
}
