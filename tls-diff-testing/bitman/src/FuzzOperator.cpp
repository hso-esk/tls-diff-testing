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

#include "FuzzOperator.h"
#include "DataUnit.h"
#include "DataUnitCursor.h"
#include "VectorDataUnit.h"
#include "EnumerationField.h"
#include "IntegerField.h"
#include "DataUnitFilter.h"
#include "OpaqueField.h"
#include "CompositeDataUnit.h"
#include "String_.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
FuzzOperator::FuzzOperator(DecisionReader& decisionReader)
		: decisionReader_(decisionReader) {
}


/*
 * ___________________________________________________________________________
 */
FuzzOperator::~FuzzOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
FuzzIntOperator::FuzzIntOperator(DecisionReader& decisionReader)
		: FuzzOperator(decisionReader) {
}


/*
 * ___________________________________________________________________________
 */
bool FuzzIntOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "FuzzIntOperator");

	if (cursor.getCurrent().containsType(IntegerField::typeDescriptor())) {

		IntegerField& intField = (IntegerField&)cursor.getCurrent();

		int before = 0;
		if (intField.propGet<int>(".value", before)) {
			log.propSet("int.before", before);
		}

		DecisionReader& decisionReader = this->getDecisionReader();

		int after;
		int max = (1 << intField.getCapacity().bit()) - 1;
		if (decisionReader.readBoolUniform()) {
			do {
				/* use the whole range */
				after = decisionReader.readUIntUniform(max + 1); // +1 is wrong?!?
			} while (after == before);
		} else {
			do {
				/* use only 0 .. 2*before + 1 */
				after = decisionReader.readUIntUniform(2 * before + 2);
			} while (after == before || after > max);
		}

		log.propSet("int.after", after);
		intField.propSet(".value", after);

		applied = true;
	}

	return applied;
}


/*
 * ___________________________________________________________________________
 */
const DataUnitFilter& FuzzIntOperator::getApplicationFilter() const {

	static DataUnitTypeFilter filter(IntegerField::typeDescriptor());
	return filter;
}


/*
 * ___________________________________________________________________________
 */
FuzzIntOperator::~FuzzIntOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
TruncationFuzzOperator::TruncationFuzzOperator(DecisionReader& decisionReader)
		: FuzzOperator(decisionReader) {
}


/*
 * ___________________________________________________________________________
 */
bool TruncationFuzzOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "TruncationFuzzOperator");

	BC oldLen = cursor.getCurrent().getLength();
	if (oldLen > 0) {
		/* truncate field to random length */
		BC newLen = this->getDecisionReader().readUIntUniform(oldLen.byte());
		cursor.getCurrent().truncate(newLen);
		applied = true;
	}

	return applied;
}


/*
 * ___________________________________________________________________________
 */
TruncationFuzzOperator::~TruncationFuzzOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
RepairingFuzzOperator::RepairingFuzzOperator(DecisionReader& decisionReader)
		: FuzzOperator(decisionReader) {
}


/*
 * ___________________________________________________________________________
 */
bool RepairingFuzzOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "RepairingFuzzOperator");

	bool fullRepair = this->getDecisionReader().readBoolUniform();

	String trace;

	DataUnit* node = &cursor.getCurrent();
	while (node != 0) {
		if (fullRepair || this->getDecisionReader().readBoolUniform()) {
			node->repair(false);
			trace.prepend("R");
		} else {
			trace.prepend("=");
		}
		node = node->getParent();
	}

	trace.prepend("[");
	trace.append(">");
	log.propSet<string>("operator.repairtrace", trace);

	return applied;
}


/*
 * ___________________________________________________________________________
 */
RepairingFuzzOperator::~RepairingFuzzOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
FuzzDataOperator::FuzzDataOperator(
		DecisionReader& decisionReader, bool preserveLen)
		: FuzzOperator(decisionReader), preserveLen_(preserveLen) {
}


/*
 * ___________________________________________________________________________
 */
bool FuzzDataOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "FuzzDataOperator");

	FieldDataUnit& fdu = (FieldDataUnit&)cursor.getCurrent();

	BC oldLen = fdu.getLength();
	BC newLen(oldLen);
	if (!preserveLen_ && (this->getDecisionReader().readBoolUniform()
			|| oldLen == 0)) {
		do {
			/* use new random length */
			newLen = this->getDecisionReader().readUIntUniform(
					oldLen.byte() * 2 + 2);
		} while (newLen == oldLen || newLen == 0);
	}

	if (newLen == oldLen) {
		/* if the length stays the same we reuse the present field */
		fdu.dissector().reset();
		fdu.dissector().dissect(this->getDecisionReader(), oldLen);
		applied = true;
	} else {
		/* if the length is changed we need to use a new field */
		OpaqueField* opaque = new OpaqueField(newLen);
		opaque->dissector().dissect(this->getDecisionReader());
		/* keep original name */
		opaque->setName(fdu.getName());
		/* replace old by new field */
		if (cursor.doReplace(opaque)) {
			applied = true;
		} else {
			delete opaque;
		}
	}

	return applied;
}


/*
 * ___________________________________________________________________________
 */
const DataUnitFilter& FuzzDataOperator::getApplicationFilter() const {

	static DataUnitTypeFilter filter(FieldDataUnit::typeDescriptor());
	return filter;
}


/*
 * ___________________________________________________________________________
 */
FuzzDataOperator::~FuzzDataOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
AppendingFuzzOperator::AppendingFuzzOperator(
		DecisionReader& decisionReader)
		: FuzzOperator(decisionReader) {
}


/*
 * ___________________________________________________________________________
 */
bool AppendingFuzzOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "AppendingFuzzOperator");

	BC len = this->getDecisionReader().readUIntUniform(4) + 1;
	OpaqueField* opaque = new OpaqueField(len);
	opaque->dissector().dissect(this->getDecisionReader());

	CompositeDataUnit& cdu =
			static_cast<CompositeDataUnit&>(cursor.getCurrent());

	if (cdu.appendChild(opaque)) {
		applied = true;
	} else {
		delete opaque;
	}

	return applied;
}


/*
 * ___________________________________________________________________________
 */
const DataUnitFilter& AppendingFuzzOperator::getApplicationFilter() const {

	static DataUnitTypeFilter filter(CompositeDataUnit::typeDescriptor());
	return filter;
}


/*
 * ___________________________________________________________________________
 */
AppendingFuzzOperator::~AppendingFuzzOperator() {
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
GeneratingFuzzOperator::GeneratingFuzzOperator(
		DecisionReader& decisionReader)
		: FuzzOperator(decisionReader) {
}


/*
 * ___________________________________________________________________________
 */
bool GeneratingFuzzOperator::generate(DataUnit& du) {

    DecisionReader& rnd = this->getDecisionReader();

    if (!du.containsType(OpaqueField::typeDescriptor())) {
		du.dissector().close();
	}

	if (du.containsType(VectorDataUnit::typeDescriptor())) {

		VectorDataUnit& vdu = (VectorDataUnit&)du;

		size_t N = rnd.readUIntExponential(5, 10);
		size_t i = 0;

		while (i < N) {
			vdu.expand(false);
			size_t n = vdu.getNChildren();
			if (n > i) {
				generate(vdu(i));
				++i;
			} else {
				break;
			}
		}

        /* TODO: make sure the last element is complete! */

		vdu.setExpanded();

		vdu.repair(false);

	} else if (du.containsType(CompositeDataUnit::typeDescriptor())) {

		CompositeDataUnit& cdu = (CompositeDataUnit&)du;

		size_t i = cdu.getNChildren();

		while (true) {
			cdu.expand(false);
			size_t n = cdu.getNChildren();
			if (n > i) {
				generate(cdu(i));
				++i;
			} else {
				break;
			}
		}

		cdu.setExpanded();

		cdu.repair(false);

	} else if (du.containsType(EnumerationField::typeDescriptor())) {

		EnumerationField& fenum = (EnumerationField&)du;

		size_t nEnumItems = fenum.getItemList().getNItems();
		int index = rnd.readUIntUniform(nEnumItems);
		const EnumerationItem& item = fenum.getItemList().getItemByIndex(index);
		fenum.propSet<int>(".value", item.getMinCode());

	} else if (du.containsType(IntegerField::typeDescriptor())) {

		IntegerField& fint = (IntegerField&)du;

		int max = (1 << fint.getCapacity().bit());
		int value = rnd.readUIntUniform(max);
		fint.propSet<int>(".value", value);

	} else if (du.containsType(OpaqueField::typeDescriptor())) {

		OpaqueField& fop = (OpaqueField&)du;

		if (fop.getCapacity().isUndef() || fop.propGetDefault("_dynlen", false)) {
			size_t N = rnd.readUIntUniform(64);
			fop.dissector().dissect(rnd.getStreamReader(), N);
		} else {
			fop.dissector().dissect(rnd.getStreamReader());
		}

		fop.dissector().close();
	}

    return true;
}


/*
 * ___________________________________________________________________________
 */
bool GeneratingFuzzOperator::apply_(DataUnitCursor& cursor, PropertyNode& log) {

	bool applied = false;

	log.propSet<string>("operator.type", "GeneratingFuzzOperator");

    cursor.getCurrent().reset();

    if (this->generate(cursor.getCurrent())) {
        applied = true;
    }

	return applied;
}


/*
 * ___________________________________________________________________________
 */
GeneratingFuzzOperator::~GeneratingFuzzOperator() {
}

