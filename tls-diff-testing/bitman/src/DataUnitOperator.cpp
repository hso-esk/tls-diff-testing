/*
 *  Copyright (C) 2017
 *  Andreas Walz [andreas.walz@hs-offenburg.de]
 *  Offenburg University of Applied Sciences
 *  Institute of Reliable Embedded Systems and Communications Electronics (ivESK)
 *  [https://ivesk.hs-offenburg.de/]
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

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
