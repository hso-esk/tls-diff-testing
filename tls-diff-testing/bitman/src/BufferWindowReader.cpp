#include <stdexcept>
#include "VectorBuffer.h"
#include "BufferWindowReader.h"

using std::vector;


/*
 * ___________________________________________________________________________
 */
BufferWindowReader::BufferWindowReader(
		const BufferReader& reader, BC offset, BC length) :
		reader_(reader), offset_(offset), length_(length) {
}


/*
 * ___________________________________________________________________________
 */
BC BufferWindowReader::getLength_() const {

	BC len = reader_.getLength();
	if (len > offset_) {
		len -= offset_;
	} else {
		len = 0;
	}
	return BC::getMin(len, length_);
}


/*
 * ___________________________________________________________________________
 */
bool BufferWindowReader::getBit_(const BC& bc) const {

	if (bc < this->getLength()) {
		return reader_.getBit(offset_ + bc);
	} else {
		throw std::runtime_error(
				"BufferWindowReader::getBit(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
uint8_t	BufferWindowReader::getByte_(const BC& bc) const {

	if ((bc + 1) <= this->getLength()) {
		return reader_.getByte(offset_ + bc);
	} else {
		throw std::runtime_error(
				"BufferWindowReader::getByte(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
BC BufferWindowReader::copyTo_(BufferWriter& buffer) const {

	return BC::undef();
}


/*
 * ___________________________________________________________________________
 */
BufferWindowReader::~BufferWindowReader() {
}
