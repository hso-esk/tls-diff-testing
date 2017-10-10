#include <stdexcept>
#include "VectorBuffer.h"
#include "BufferStreamReader.h"

using std::vector;


/*
 * ___________________________________________________________________________
 */
BufferStreamReader::BufferStreamReader(const BufferReader& reader) :
		reader_(reader), pos_(0) {
}


/*
 * ___________________________________________________________________________
 */
uint8_t BufferStreamReader::readByte_(bool remove) {

	/* bounds checked by underlying BufferReader */
	uint8_t byte = reader_.getByte(pos_);
	if (remove) {
		++pos_;
	}
	return byte;
}


/*
 * ___________________________________________________________________________
 */
bool BufferStreamReader::readBit_(bool remove) {

	/* bounds checked by underlying BufferReader */
	bool bit = reader_.getBit(pos_);
	if (remove) {
		pos_ <<= 1;
	}
	return bit;
}


/*
 * ___________________________________________________________________________
 */
BC BufferStreamReader::getLength_() const {

	BC len = reader_.getLength();
	if (len > pos_) {
		len -= pos_;
	} else {
		len = 0;
	}
	return len;
}


/*
 * ___________________________________________________________________________
 */
bool BufferStreamReader::getBit_(const BC& bc) const {

	/* bounds checked by underlying BufferReader */
	return reader_.getBit(pos_ + bc);
}


/*
 * ___________________________________________________________________________
 */
uint8_t	BufferStreamReader::getByte_(const BC& bc) const {

	/* bounds checked by underlying BufferReader */
	return reader_.getByte(pos_ + bc);
}


/*
 * ___________________________________________________________________________
 */
BC BufferStreamReader::copyTo_(BufferWriter& buffer) const {

	return BC::undef();
}


/*
 * ___________________________________________________________________________
 */
BufferStreamReader::~BufferStreamReader() {
}
