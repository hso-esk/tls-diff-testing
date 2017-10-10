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

#include "DataUnitFilter.h"
#include "DataUnit.h"

using std::vector;


/*
 * ___________________________________________________________________________
 */
DataUnitFilter::DataUnitFilter() {
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitFilter::apply(const DataUnit& dataUnit) const {

	return true;
}


/*
 * ___________________________________________________________________________
 */
DataUnitFilter::~DataUnitFilter() {
}


/*
 * ===========================================================================
 */


/*
* ___________________________________________________________________________
*/
ConjunctionDataUnitFilter::ConjunctionDataUnitFilter(
		const DataUnitFilter& filter1, const DataUnitFilter& filter2)
		: DataUnitFilter() {

	filters_.push_back(&filter1);
	filters_.push_back(&filter2);
}


/*
* ___________________________________________________________________________
*/
ConjunctionDataUnitFilter::ConjunctionDataUnitFilter(
		const DataUnitFilter& filter1, const DataUnitFilter& filter2,
		const DataUnitFilter& filter3) : DataUnitFilter() {

	filters_.push_back(&filter1);
	filters_.push_back(&filter2);
	filters_.push_back(&filter3);
}


/*
* ___________________________________________________________________________
*/
bool ConjunctionDataUnitFilter::apply(const DataUnit& dataUnit) const {

	bool passes = true;

	size_t n = filters_.size();
	for (size_t i = 0; passes && i < n; ++i) {
		const DataUnitFilter* filter = filters_[i];
		if (filter != 0) {
			passes &= filters_[i]->apply(dataUnit);
		}
	}

	return passes;
}


/*
* ___________________________________________________________________________
*/
ConjunctionDataUnitFilter::~ConjunctionDataUnitFilter() {
}


/*
 * ===========================================================================
 */


/*
* ___________________________________________________________________________
*/
InvertingDataUnitFilter::InvertingDataUnitFilter(
		const DataUnitFilter& filter) : DataUnitFilter(), filter_(filter) {
}


/*
* ___________________________________________________________________________
*/
bool InvertingDataUnitFilter::apply(const DataUnit& dataUnit) const {

	return !filter_.apply(dataUnit);
}


/*
* ___________________________________________________________________________
*/
InvertingDataUnitFilter::~InvertingDataUnitFilter() {
}


/*
* ===========================================================================
*/


/*
 * ___________________________________________________________________________
 */
DataUnitTypeFilter::DataUnitTypeFilter(const TypeDescriptor& type,
		bool strict, bool inclusive) : DataUnitFilter(), filterType_(type),
		strict_(strict), inclusive_(inclusive) {
}


/*
 * ___________________________________________________________________________
 */
bool DataUnitTypeFilter::apply(const DataUnit& dataUnit) const {

	bool passes = false;

	if (strict_) {
		passes = dataUnit.isOfType(filterType_);
	} else if (inclusive_) {
		passes = dataUnit.containsType(filterType_);
	} else {
		passes = dataUnit.inheritsFromType(filterType_);
	}

	return passes;
}


/*
 * ___________________________________________________________________________
 */
DataUnitTypeFilter::~DataUnitTypeFilter() {
}
