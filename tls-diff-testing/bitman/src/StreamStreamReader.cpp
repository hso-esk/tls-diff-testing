#include <stdexcept>
#include "StreamStreamReader.h"

using std::vector;


/*
 * ___________________________________________________________________________
 */
StreamStreamReader::StreamStreamReader(StreamReader& reader)
		: len_(-1), reader_(reader) {
}


/*
 * ___________________________________________________________________________
 */
StreamStreamReader::StreamStreamReader(StreamReader& reader, const BC& len)
		: len_(len), reader_(reader) {
}


/*
 * ___________________________________________________________________________
 */
bool StreamStreamReader::getBit_(const BC& bc) const {

	if (len_.isUndef() || bc < len_) {
		return reader_.getBit(bc);
	} else {
		throw std::runtime_error(
				"StreamStreamReader::getBit(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
uint8_t StreamStreamReader::getByte_(const BC& bc) const {

	if (len_.isUndef() || (bc + 1) <= len_) {
		return reader_.getByte(bc);
	} else {
		throw std::runtime_error(
				"StreamStreamReader::getByte(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
BC StreamStreamReader::copyTo_(BufferWriter& buffer) const {

	return BC::undef();
}


/*
 * ___________________________________________________________________________
 */
BC StreamStreamReader::getLength_() const {

	BC len = reader_.getLength();
	if (len_.isDef() && len_ < len) {
		len = len_;
	}
	return len;
}


/*
 * ___________________________________________________________________________
 */
uint8_t StreamStreamReader::readByte_(bool remove) {

	if (len_.isUndef() || len_ >= 1) {
		uint8_t byte = reader_.readByte(remove);
		if (remove) {
			len_--;
		}
		return byte;
	} else {
		throw std::runtime_error(
				"StreamStreamReader::readByte(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
bool StreamStreamReader::readBit_(bool remove) {

	if (len_.isUndef() || len_ > 0) {
		bool bit = reader_.readBit(remove);
		if (remove) {
			len_ >>= 1;
		}
		return bit;
	} else {
		throw std::runtime_error(
				"StreamStreamReader::readBit(...): Out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
StreamStreamReader::~StreamStreamReader() {
}

