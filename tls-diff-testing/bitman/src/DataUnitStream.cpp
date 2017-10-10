#include <DataUnitStream.h>
#include "StreamReader.h"
#include "DataUnit.h"
#include "DataUnitFragment.h"

using std::vector;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor DataUnitStream::desc_(
		StreamVectorDataUnit::typeDescriptor(), 0, "DataUnitStream");


/*
 * ___________________________________________________________________________
 */
DataUnitStream::DataUnitStream(DataUnit* unit) {

	this->setElementTemplate(unit);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& DataUnitStream::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
DataUnitFragment* DataUnitStream::newFragment(const BC& size) {

	DataUnitFragment* sdu = new DataUnitFragment(*this, size);
	fragments_.push_back(sdu);
	return sdu;
}


/*
 * ___________________________________________________________________________
 */
DataUnitStream::~DataUnitStream() {

	while (fragments_.size() > 0) {
		delete fragments_.back();
		fragments_.pop_back();
	}
}

