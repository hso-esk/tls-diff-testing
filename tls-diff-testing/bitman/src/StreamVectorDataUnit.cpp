#include "StreamVectorDataUnit.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor StreamVectorDataUnit::desc_(
		VectorDataUnit::typeDescriptor(), 0, "StreamVectorDataUnit");


/*
 * ___________________________________________________________________________
 */
StreamVectorDataUnit::StreamVectorDataUnit() :
		VectorDataUnit(false), N_(-1) {

}


/*
 * ___________________________________________________________________________
 */
StreamVectorDataUnit::StreamVectorDataUnit(const BC& N) :
		VectorDataUnit(N == 0), N_(N) {

	this->dissector().setSize(N_);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& StreamVectorDataUnit::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
bool StreamVectorDataUnit::expand_(
		size_t len, size_t decoded, bool dry, bool ahead) {

	bool ret = true;

	if (N_.isUndef() || this->dissector().getLength() < N_) {

		DataUnit* tail = this->getChildTail();
		if (!dry && (tail == 0 || !tail->dissector().isAccepting())) {
			/* create a new instance of the template data
			 * unit and attach it to the list of children */
			DataUnit* elementTemplate = this->getElementTemplate();
			if (elementTemplate != 0) {
				this->appendChild(elementTemplate->newInstance());
			}
		}

		/* this vector is not yet satisfied and expects to get more input */
		ret = false;
	}

	return ret;
}


/*
 * ___________________________________________________________________________
 */
DataUnit* StreamVectorDataUnit::newInstance_() const {

	StreamVectorDataUnit* vector = new StreamVectorDataUnit(N_);
	DataUnit* elementTemplate = this->getElementTemplate();
	if (elementTemplate != 0) {
		vector->setElementTemplate(elementTemplate->newInstance());
	}
	return vector;
}


/*
 * ___________________________________________________________________________
 */
StreamVectorDataUnit::~StreamVectorDataUnit() {
}

