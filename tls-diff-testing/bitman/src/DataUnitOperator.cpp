#include <string>
#include "DataUnitOperator.h"
#include "DataUnitFilter.h"
#include "DataUnitCursor.h"
#include "DataUnit.h"
#include "VoidField.h"
#include "OpaqueField.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
DataUnitOperator::DataUnitOperator() {
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitOperator::apply(DataUnitCursor& cursor) {

	bool applied = false;

	lastOpLog_.propClear();

	if (cursor.valid()) {
		DataUnit& operand = cursor.getCurrent();

		lastOpLog_.propSet("operand.path", operand.getChainedRefName());
		lastOpLog_.propSet("operand.type", operand.getTypeName());
		lastOpLog_.propSet("operand.inherit", operand.getTypeInheritance());
		lastOpLog_.propSet("operand.length", operand.getLength().toString());

		if (this->getApplicationFilter().apply(operand)) {
			applied = this->apply_(cursor, lastOpLog_);
		}

		if (applied && cursor.valid()) {
			lastOpLog_.propSet("operand.length.after",
					cursor.getCurrent().getLength().toString());
		}
	}

	lastOpLog_.propSet("operator.applied", applied ? 1 : 0);

	return applied;
}


/*
 * ___________________________________________________________________________
 */
const DataUnitFilter& DataUnitOperator::getApplicationFilter() const {

	/* return a transparent filter */
	static DataUnitFilter filter;
	return filter;
}


/*
 * ___________________________________________________________________________
 */
DataUnitOperator::~DataUnitOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
VoidingOperator::VoidingOperator() : DataUnitOperator() {
}


/*
 * ___________________________________________________________________________
 */
bool VoidingOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "VoidingOperator");

	VoidField* field = new VoidField();
	if (cursor.doReplace(field)) {
		applied = true;
	} else {
		delete field;
	}

	return applied;
}


/*
 * ___________________________________________________________________________
 */
VoidingOperator::~VoidingOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
OpacifyingOperator::OpacifyingOperator() : DataUnitOperator() {
}


/*
 * ___________________________________________________________________________
 */
const DataUnitFilter& OpacifyingOperator::getApplicationFilter() const {

	static DataUnitTypeFilter filter(OpaqueField::typeDescriptor(), true);
	static InvertingDataUnitFilter invFilter(filter);
	return invFilter;
}


/*
 * ___________________________________________________________________________
 */
bool OpacifyingOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "OpacifyingOperator");

	OpaqueField* opaque = new OpaqueField(cursor.getCurrent().getLength());
	opaque->dissector().dissectFromBuffer(cursor.getCurrent());

	if (cursor.doReplace(opaque)) {
		applied = true;
	} else {
		delete opaque;
	}

	return applied;
}


/*
 * ___________________________________________________________________________
 */
OpacifyingOperator::~OpacifyingOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
DuplicatingOperator::DuplicatingOperator() : DataUnitOperator() {
}


/*
 * ___________________________________________________________________________
 */
bool DuplicatingOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "DuplicatingOperator");

	DataUnit* cloned = cursor.getCurrent().clone();
	if (cursor.doInsert(cloned)) {
		applied = true;
	} else {
		delete cloned;
	}

	return applied;
}


/*
 * ___________________________________________________________________________
 */
DuplicatingOperator::~DuplicatingOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
DeletingOperator::DeletingOperator() : DataUnitOperator() {
}


/*
 * ___________________________________________________________________________
 */
bool DeletingOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	log.propSet<string>("operator.type", "DeletingOperator");

	return cursor.doDelete();
}


/*
 * ___________________________________________________________________________
 */
DeletingOperator::~DeletingOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
RepairingOperator::RepairingOperator() : DataUnitOperator() {
}


/*
 * ___________________________________________________________________________
 */
bool RepairingOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = true;

	log.propSet<string>("operator.type", "RepairingOperator");

	DataUnit* node = &cursor.getCurrent();
	while (node != 0 && applied) {
		applied &= node->repair(false);
		node = node->getParent();
	}

	return applied;
}


/*
 * ___________________________________________________________________________
 */
RepairingOperator::~RepairingOperator() {
}
