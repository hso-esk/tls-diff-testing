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

#ifndef __DataUnitCursor_H__
#define __DataUnitCursor_H__

#include <cstdlib>
#include <inttypes.h>
#include <vector>
#include "DataUnit.h"

class DataUnitFilter;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DataUnitCursor {

private:

	/* TODO: Add description */
	DataUnit& root_;

	/* TODO: Add description */
	DataUnit* position_;

	/* TODO: Add description */
	const DataUnitFilter* globalFilter_;


	/* TODO: Add description */
	bool applyFilter(const DataUnit* dataUnit,
			const DataUnitFilter* filter = 0) const;

	/* TODO: Add description */
	size_t scan(std::vector<DataUnit*>* dataUnits,
			const DataUnitFilter* filter = 0) const;

	/* TODO: Add description */
	size_t printScan_(const DataUnitFilter* filter, bool printAll) const;

	/* TODO: Add description */
	bool seekByIndex_(size_t n, const DataUnitFilter* filter);


public:

	/* TODO: Add description */
	DataUnitCursor(DataUnit& root);

	/* TODO: Add description */
	DataUnitCursor(DataUnit& root, DataUnit& position);

	/* TODO: Add description */
	DataUnitCursor(DataUnit& root, const DataUnitFilter& filter);

	/* TODO: Add description */
	DataUnitCursor(DataUnit& root, DataUnit& position,
			const DataUnitFilter& filter);


	/* TODO: Add description */
	inline const DataUnit& getRoot() const {

		return root_;
	}

	/* TODO: Add description */
	inline DataUnit* getPosition() {

		return position_;
	}

	/* TODO: Add description */
	inline DataUnit& getCurrent() {

		return *position_;
	}

	/* TODO: Add description */
	inline bool valid() const {

		return position_ != 0;
	}


	/* TODO: Add description */
	bool moveTo(DataUnit* position);

	/* TODO: Add description */
	bool setTo(DataUnit* position);

	/* TODO: Add description */
	inline bool moveTo(DataUnit& position) {

		return this->moveTo(&position);
	}

	/* TODO: Add description */
	inline bool seekByIndex(size_t n) {

		return this->seekByIndex_(n, (const DataUnitFilter*)0);
	}

	/* TODO: Add description */
	inline bool seekByIndex(size_t n, const DataUnitFilter& filter) {

		return this->seekByIndex_(n, &filter);
	}

	/* TODO: Add description */
	inline bool seekByPath(const std::string& path) {

		return this->moveTo(root_.getByPath(path));
	}

	/* TODO: Add description */
	inline bool moveToRoot() {

		return this->moveTo(root_);
	}

	/* TODO: Add description */
	bool moveToEnd();


	/* TODO: Add description */
	bool moveRight(size_t steps = 1, const DataUnitFilter* filter = 0);

	/* TODO: Add description */
	bool moveLeft(size_t steps = 1, const DataUnitFilter* filter = 0);

	/* TODO: Add description */
	bool moveUp(size_t steps = 1, const DataUnitFilter* filter = 0);

	/* TODO: Add description */
	bool moveDown(size_t steps = 1, const DataUnitFilter* filter = 0);

	/* TODO: Add description */
	bool moveForward(size_t steps = 1, const DataUnitFilter* filter = 0);

	/* TODO: Add description */
	bool moveBackward(size_t steps = 1, const DataUnitFilter* filter = 0);


	/* TODO: Add description */
	inline size_t printScan() const {

		return this->printScan_((const DataUnitFilter*)0, true);
	}

	/* TODO: Add description */
	inline size_t printScan(const DataUnitFilter& filter,
			bool printAll = false) const {

		return this->printScan_(&filter, printAll);
	}

	/* TODO: Add description */
	inline size_t count() const {

		return this->scan((std::vector<DataUnit*>*)0, (const DataUnitFilter*)0);
	}

	/* TODO: Add description */
	inline size_t count(const DataUnitFilter& filter) const {

		return this->scan((std::vector<DataUnit*>*)0, &filter);
	}

	/* TODO: Add description */
	inline size_t enumerate(std::vector<DataUnit*>& dataUnits) const {

		return this->scan(&dataUnits, (const DataUnitFilter*)0);
	}

	/* TODO: Add description */
	inline size_t enumerate(std::vector<DataUnit*>& dataUnits,
			const DataUnitFilter& filter) const {

		return this->scan(&dataUnits, &filter);
	}


	/* TODO: Add description */
	bool doInsert(DataUnit* insertion);

	/* TODO: Add description */
	bool doReplace(DataUnit* replacement);

	/* TODO: Add description */
	bool doTruncate(const BC& length);

	/* TODO: Add description */
	bool doRemove();

	/* TODO: Add description */
	bool doDelete();


	/* TODO: Add description */
	virtual ~DataUnitCursor();

};

#endif
