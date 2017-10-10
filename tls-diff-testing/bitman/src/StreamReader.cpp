#include "StreamReader.h"


/*
 * ___________________________________________________________________________
 */
StreamReader::StreamReader() : accu_(0) {
}


/*
 * ___________________________________________________________________________
 */
uint8_t StreamReader::readByte(bool remove) {

	uint8_t byte = this->readByte_(remove);
	if (remove) {
		++accu_;
	}
	return byte;
}


/*
 * ___________________________________________________________________________
 */
bool StreamReader::readBit(bool remove) {

	bool bit = this->readBit_(remove);
	if (remove) {
		accu_ <<= 1;
	}
	return bit;
}


/*
 * ___________________________________________________________________________
 */
BC StreamReader::flush(const BC& max) {

	BC len = BC::getMin(this->getLength(), max);
	BC ret = len;

	if (len.isDef()) {
		while (len >= 1) {
			this->readByte();
			len--;
		}
		while (len > 0) {
			this->readBit();
			len >>= 1;
		}
	} else {
		ret = 0;
	}

	return ret;
}


/*
 * ___________________________________________________________________________
 */
StreamReader::~StreamReader() {
}

