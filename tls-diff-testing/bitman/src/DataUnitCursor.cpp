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

#include <stdexcept>
#include <iostream>
#include <vector>
#include "DataUnitCursor.h"
#include "DataUnit.h"
#include "DataUnitFilter.h"
#include "String_.h"

using std::cout;
using std::endl;
using std::vector;


/*
 * ___________________________________________________________________________
 */
DataUnitCursor::DataUnitCursor(DataUnit& root)
		: root_(root), position_(0), globalFilter_(0) {

	/* move to first position after root matching criteria */
	this->seekByIndex((size_t)0);
}


/*
 * ___________________________________________________________________________
 */
DataUnitCursor::DataUnitCursor(DataUnit& root, DataUnit& position)
		: root_(root), position_(0), globalFilter_(0) {

	this->moveTo(position);
}


/*
 * ___________________________________________________________________________
 */
DataUnitCursor::DataUnitCursor(DataUnit& root, const DataUnitFilter& filter)
		: root_(root), position_(0), globalFilter_(&filter) {

	/* move to first position after root matching criteria */
	this->seekByIndex((size_t)0);
}


/*
 * ___________________________________________________________________________
 */
DataUnitCursor::DataUnitCursor(DataUnit& root, DataUnit& position,
		const DataUnitFilter& filter)
		: root_(root), position_(0), globalFilter_(&filter) {

	this->moveTo(position);
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::applyFilter(const DataUnit* dataUnit,
		const DataUnitFilter* filter) const {

	bool passes = true;

	if (dataUnit != 0) {
		if (globalFilter_ != 0 && !globalFilter_->apply(*dataUnit)) {
			passes = false;
		}
		if (filter != 0 && !filter->apply(*dataUnit)) {
			passes = false;
		}
		if (!dataUnit->isDescendantOf(root_) && dataUnit != &root_) {
			passes = false;
		}
	}

	return passes;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::moveTo(DataUnit* position) {

	bool accepted = false;
	if (position != 0 && applyFilter(position)) {
		position_ = position;
		accepted = true;
	}
	return accepted;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::setTo(DataUnit* position) {

	bool accepted = this->moveTo(position);
	if (!accepted) {
		position_ = (DataUnit*)0;
	}
	return accepted;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::seekByIndex_(size_t n, const DataUnitFilter* filter) {

	DataUnit* pos = &root_;
	/* move to index 0, i.e. first position from root matching criteria */
	while (!applyFilter(pos, filter)) {
		pos = pos->getSuccessor();
	}
	/* now move ahead n positions matching criteria */
	while ((pos != 0) && (n > 0)) {
		pos = pos->getSuccessor();
		if (applyFilter(pos, filter)) {
			--n;
		}
	}
	return this->moveTo(pos);
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::moveToEnd() {

	DataUnit* pos = position_;
	DataUnit* tst = position_;
	while (tst != 0) {
		pos = tst;
		tst = tst->getSuccessor();
	}
	return this->moveTo(pos);
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::moveRight(size_t steps, const DataUnitFilter* filter) {

	DataUnit* pos = position_;
	while ((pos != 0) && (steps > 0)) {
		pos = pos->getNext();
		if (applyFilter(pos, filter)) {
			--steps;
		}
	}
	return this->moveTo(pos);
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::moveLeft(size_t steps, const DataUnitFilter* filter) {

	DataUnit* pos = position_;
	while ((pos != 0) && (steps > 0)) {
		pos = pos->getPrevious();
		if (applyFilter(pos, filter)) {
			--steps;
		}
	}
	return this->moveTo(pos);
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::moveUp(size_t steps, const DataUnitFilter* filter) {

	DataUnit* pos = position_;
	while ((pos != 0) && (steps > 0)) {
		pos = pos->getParent();
		if (applyFilter(pos, filter)) {
			--steps;
		}
	}
	return this->moveTo(pos);
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::moveDown(size_t steps, const DataUnitFilter* filter) {

	DataUnit* pos = position_;
	while ((pos != 0) && (steps > 0)) {
		pos = pos->getChild();
		if (applyFilter(pos, filter)) {
			--steps;
		}
	}
	return this->moveTo(pos);
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::moveForward(size_t steps, const DataUnitFilter* filter) {

	DataUnit* pos = position_;
	while ((pos != 0) && (steps > 0)) {
		pos = pos->getSuccessor();
		if (applyFilter(pos, filter)) {
			--steps;
		}
	}
	return this->moveTo(pos);
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::moveBackward(size_t steps, const DataUnitFilter* filter) {

	DataUnit* pos = position_;
	while ((pos != 0) && (steps > 0)) {
		pos = pos->getPredecessor();
		if (applyFilter(pos, filter)) {
			--steps;
		}
	}
	return this->moveTo(pos);
}


/*
 * ___________________________________________________________________________
 */
size_t DataUnitCursor::scan(std::vector<DataUnit*>* dataUnits,
		const DataUnitFilter* filter) const {

	size_t n = 0;

	DataUnit* pos = &root_;
	while (pos != 0) {
		if (applyFilter(pos, filter)) {
			if (dataUnits != 0) {
				dataUnits->push_back(pos);
			}
			++n;
		}
		pos = pos->getSuccessor();
	}

	return n;
}


/*
 * ___________________________________________________________________________
 */
size_t DataUnitCursor::printScan_(
		const DataUnitFilter* filter, bool printAll) const {

	vector<DataUnit*> dataUnits;
	this->scan(&dataUnits);

	size_t max = 9;
	size_t w = 1;
	while (dataUnits.size() > max) {
		++w;
		max = (max + 1) * 10 - 1;
	}

	for (size_t i = 0; i < dataUnits.size(); ++i) {

		bool passFilter = true;
		if (filter != 0 && !filter->apply(*(dataUnits[i]))) {
			passFilter = false;
		}

		/* print cursor position */
		if (printAll || passFilter) {

			/* print index */
			cout << String::format("%*u: ", w, i);

			if (position_ != 0) {
				if (dataUnits[i] == position_) {
					cout << "=> ";
				} else {
					cout << "   ";
				}
			}
		}

		/* print paths (including filter results) */
		if (printAll && passFilter) {
			cout << String::makeBoldRed(dataUnits[i]->getPath()) << endl;
		} else if (printAll || passFilter) {
			cout << dataUnits[i]->getPath() << endl;
		}
	}

	return dataUnits.size();
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::doInsert(DataUnit* insertion) {

	bool success = false;

	/* cannot insert at root. TODO: make this possible */
	if (this->valid() && position_ != &root_) {
		DataUnit* current = position_;
		if (current->insert(insertion)) {
			success = true;
			/* set to insertion */
			this->setTo(insertion);
		}
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::doReplace(DataUnit* replacement) {

	bool success = false;

	/* cannot replace root. TODO: make this possible */
	if (this->valid() && position_ != &root_) {
		DataUnit* current = position_;
		if (current->replaceBy(replacement)) {
			success = true;
			/* delete previously current data unit */
			delete current;
			/* set to replacement */
			this->setTo(replacement);
		}
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::doTruncate(const BC& length) {

	bool success = false;

	if (this->valid()) {
		position_->truncate(length);
		success = true;
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::doRemove() {

	bool success = false;

	/* cannot remove root TODO: make this possible */
	if (this->valid() && position_ != &root_) {
		DataUnit* current = position_;
		DataUnit* parent = position_->getParent();
		/* remove node at current position */
		current->remove();
		success = true;
		/* set to parent of removed node */
		this->setTo(parent);
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitCursor::doDelete() {

	bool success = false;

	DataUnit* current = position_;
	if (this->doRemove()) {
		delete current;
		success = true;
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
DataUnitCursor::~DataUnitCursor() {
}

