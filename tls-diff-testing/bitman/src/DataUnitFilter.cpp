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
