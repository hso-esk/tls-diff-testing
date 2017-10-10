#include "VectorDataUnit.h"


/*
 * ___________________________________________________________________________
 */
TypeDescriptor VectorDataUnit::desc_(
		CompositeDataUnit::typeDescriptor(), 0, "VectorDataUnit");


/*
 * ___________________________________________________________________________
 */
VectorDataUnit::VectorDataUnit() : CompositeDataUnit(), template_(0) {
}


/*
 * ___________________________________________________________________________
 */
VectorDataUnit::VectorDataUnit(bool empty)
	: CompositeDataUnit(empty), template_(0) {
}


/*
 * ___________________________________________________________________________
 */
VectorDataUnit::VectorDataUnit(DataUnit* elementTemplate) :
		CompositeDataUnit(), template_(elementTemplate) {

}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& VectorDataUnit::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
void VectorDataUnit::setElementTemplate(DataUnit* elementTemplate) {

	if (template_ != 0) {
		delete template_;
	}
	template_ = elementTemplate;
}


/*
 * ___________________________________________________________________________
 */
DataUnit* VectorDataUnit::getElementTemplate() const {

	return template_;
}


/*
 * ___________________________________________________________________________
 */
VectorDataUnit::~VectorDataUnit() {

	/* delete the template if one has been given */
	if (template_ != 0) {
		delete template_;
	}
}

