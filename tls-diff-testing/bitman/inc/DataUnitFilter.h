#ifndef __DataUnitFilter_H__
#define __DataUnitFilter_H__

#include <vector>

class DataUnit;
class TypeDescriptor;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DataUnitFilter {

public:

	/* TODO: Add description */
	DataUnitFilter();


	/* TODO: Add description */
	virtual bool apply(const DataUnit& dataUnit) const;


	/* TODO: Add description */
	virtual ~DataUnitFilter();

};


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class InvertingDataUnitFilter : public DataUnitFilter {

private:

	/* TODO: Add description */
	const DataUnitFilter& filter_;


public:

	/* TODO: Add description */
	InvertingDataUnitFilter(const DataUnitFilter& filter);


	/* TODO: Add description */
	virtual bool apply(const DataUnit& dataUnit) const;


	/* TODO: Add description */
	virtual ~InvertingDataUnitFilter();

};


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class ConjunctionDataUnitFilter : public DataUnitFilter {

private:

	/* TODO: Add description */
	std::vector<const DataUnitFilter*> filters_;


public:

	/* TODO: Add description */
	ConjunctionDataUnitFilter(const DataUnitFilter& filter1,
			const DataUnitFilter& filter2);

	/* TODO: Add description */
	ConjunctionDataUnitFilter(const DataUnitFilter& filter1,
			const DataUnitFilter& filter2, const DataUnitFilter& filter3);


	/* TODO: Add description */
	virtual bool apply(const DataUnit& dataUnit) const;


	/* TODO: Add description */
	virtual ~ConjunctionDataUnitFilter();

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DataUnitTypeFilter : public DataUnitFilter {

private:

	/* TODO: Add description */
	const TypeDescriptor& filterType_;

	/* TODO: Add description */
	bool strict_;

	/* TODO: Add description */
	bool inclusive_;


public:

	/* TODO: Add description */
	DataUnitTypeFilter(const TypeDescriptor& type,
			bool strict = false, bool inclusive = true);


	/* TODO: Add description */
	bool apply(const DataUnit& dataUnit) const;


	/* TODO: Add description */
	virtual ~DataUnitTypeFilter();

};

#endif
