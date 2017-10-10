#include "DecisionReader.h"
#include "IntegerField.h"
#include <stdexcept>


/*
 * ___________________________________________________________________________
 */
DecisionReader::DecisionReader(StreamReader& streamer) : streamer_(streamer) {
}


/*
 * ___________________________________________________________________________
 */
bool DecisionReader::readBoolUniform() {

	return this->readBit();
}


/*
 * ___________________________________________________________________________
 */
size_t DecisionReader::readUIntUniform(size_t max) {

	if (max == 0) {
		throw std::runtime_error("DecisionReader::readUIntUniform(...): "
				"'max' needs to be larger than zero");
	}

	/* determine bit width of requested integer */
	size_t width = 1;
	while (width < 31 && max > (size_t)(1 << width)) {
		width++;
	}

	size_t value;
	IntegerField intField(BC(0, width));

	do {
		intField.dissector().reset();
		intField.dissector().dissect(*this);
		value = (size_t)intField.getValue<unsigned int>();
	} while (value >= max);

	return value;
}


/*
 * ___________________________________________________________________________
 */
size_t DecisionReader::readUIntExponential(size_t num, size_t denom) {

	size_t value = 0;

	while (this->readUIntUniform(denom) <= num) {
		++value;
	}

	return value;
}


/*
 * ___________________________________________________________________________
 */
DecisionReader::~DecisionReader() {
}

