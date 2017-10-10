#include "StaticVectorDataUnit.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor StaticVectorDataUnit::desc_(
		VectorDataUnit::typeDescriptor(), 0, "StaticVectorDataUnit");


/*
 * ___________________________________________________________________________
 */
StaticVectorDataUnit::StaticVectorDataUnit(size_t N) :
		VectorDataUnit(N == 0), N_(N) {

}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& StaticVectorDataUnit::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
bool StaticVectorDataUnit::expand_(
		size_t len, size_t decoded, bool dry, bool ahead) {

	DataUnit* elementTemplate = this->getElementTemplate();
	for (size_t i = len; i < N_; i++) {
		this->appendChild(elementTemplate->newInstance());
	}
	return true;
}


/*
 * ___________________________________________________________________________
 */
DataUnit* StaticVectorDataUnit::newInstance_() const {

	StaticVectorDataUnit* vector = new StaticVectorDataUnit(N_);
	DataUnit* elementTemplate = this->getElementTemplate();
	if (elementTemplate != 0) {
		vector->setElementTemplate(elementTemplate->newInstance());
	}
	return vector;
}


/*
 * ___________________________________________________________________________
 */
StaticVectorDataUnit::~StaticVectorDataUnit() {
}

