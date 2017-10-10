#include "DataUnitVisitor.h"
#include "DataUnit.h"


/*
 * ___________________________________________________________________________
 */
DataUnitVisitor::DataUnitVisitor() {
}


/*
 * ___________________________________________________________________________
 */
size_t DataUnitVisitor::visit(DataUnit& dataUnit, size_t index, size_t depth) {

	size_t N = 0;

	if (this->visiting(dataUnit, index, depth)) {
		N++;
		/* visit children */
		size_t i = 0;
		DataUnit* child = dataUnit.getChild(0);
		while (child != 0) {
			N += this->visit(*child, i++, depth + 1);
			child = child->getNext();
		}
	}

	return N;
}


/*
 * ___________________________________________________________________________
 */
size_t DataUnitVisitor::visit(DataUnit& dataUnit) {

	return this->visit(dataUnit, dataUnit.getIndexOffset(), 0);
}


/*
 * ___________________________________________________________________________
 */
DataUnitVisitor::~DataUnitVisitor() {
}

