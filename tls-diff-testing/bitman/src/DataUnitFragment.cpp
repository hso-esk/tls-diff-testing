#include <stdexcept>
#include "DataUnitStream.h"
#include "DataUnitFragment.h"
#include "String_.h"

using std::string;
using std::vector;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor DataUnitFragment::desc_(
		DataUnit::typeDescriptor(), 0, "DataUnitFragment");


/*
 * ___________________________________________________________________________
 */
DataUnitFragment::DataUnitFragment(DataUnitStream& protocol, const BC& size) :
		protocol_(protocol), offset_(protocol.getLength()), len_(0) {

	this->dissector().setSize(size);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& DataUnitFragment::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
void DataUnitFragment::printBody(const PrintOptions& options) const {

	PrintOptions myOptions(options);

	myOptions.from = offset_;
	myOptions.to = offset_ + this->dissector().getLength();
	myOptions.bodyOnly = true;

	protocol_.print(myOptions);
}


/*
 * ___________________________________________________________________________
 */
string DataUnitFragment::getAnchorBrackets_() const {

	return "<>";
}


/*
 * ___________________________________________________________________________
 */
void DataUnitFragment::dissectorBodyReset() {

	/* nothing to here (at least for now) */
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitFragment::dissectorBodyIsAccepting() const {

	return protocol_.dissector().isAccepting();
}


/*
 * ___________________________________________________________________________
 */
BC DataUnitFragment::dissectorBodyDissect(StreamReader& reader) {

	BC len = protocol_.dissector().dissect(reader);
	len_ += len;
	return len;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitFragment::getBit_(const BC& bc) const {

	if (bc < len_) {
		return protocol_.getBit(offset_ + bc);
	} else {
		throw std::runtime_error("DataUnitFragment::getBit_(...): "
				"Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
uint8_t	DataUnitFragment::getByte_(const BC& bc) const {

	if (bc + 1 <= len_) {
		return protocol_.getByte(offset_ + bc);
	} else {
		throw std::runtime_error("DataUnitFragment::getByte_(...): "
				"Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
BC DataUnitFragment::copyTo_(BufferWriter& buffer) const {

	return BC::undef();
}


/*
 * ___________________________________________________________________________
 */
BC DataUnitFragment::getLength_() const {

	return len_;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitFragment::appendBit(bool bit) {

	throw std::runtime_error("DataUnitFragment::appendBit(...): "
			"Not yet implemented");
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitFragment::appendByte(uint8_t byte) {

	throw std::runtime_error("DataUnitFragment::appendByte(...): "
			"Not yet implemented");
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitFragment::setBit(const BC& bc, bool bit) {

	throw std::runtime_error("DataUnitFragment::setBit(...): "
			"Not yet implemented");
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitFragment::setByte(const BC& bc, uint8_t byte) {

	throw std::runtime_error("DataUnitFragment::setByte(...): "
			"Not yet implemented");
}


/*
 * ___________________________________________________________________________
 */
void DataUnitFragment::clear() {

	throw std::runtime_error("DataUnitFragment::clear(): "
			"Not yet implemented");
}


/*
 * ___________________________________________________________________________
 */
void DataUnitFragment::truncate(const BC& length) {

	throw std::runtime_error("DataUnitFragment::truncate(...): "
			"Not yet implemented");
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitFragment::isDecoded_() const {

	return true;
}


/*
 * ___________________________________________________________________________
 */
DataUnitFragment::~DataUnitFragment() {
}
