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
