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

#ifndef __PropertyNode_H__
#define __PropertyNode_H__

#include <string>
#include <inttypes.h>
#include <map>
#include "Value.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class PropertyNode {

private:

	/* TODO: Add description */
	typedef std::map<std::string, DynamicValue> map_type_t;

	/* TODO: Add description */
	map_type_t properties_;


	/* TODO: Add description */
	size_t findUnique(const std::string& prefix,
			size_t offset = 0, size_t max = 0) const;


protected:

	/* TODO: Add description */
	virtual bool propRedirectHook_(std::string& name,
			PropertyNode*& node) const;

	/* TODO: Add description */
	virtual void propReadHook_(const std::string& name,
			DynamicValue& value) const;

	/* TODO: Add description */
	virtual void propWriteHook_(const std::string& name, DynamicValue& value);


public:

	/* TODO: Add description */
	PropertyNode();

	/* TODO: Add description */
	PropertyNode(const PropertyNode& propertyNode);


	/* TODO: Add description */
	template<typename T>
	bool propSet(const std::string& name, const T& value);

	/* TODO: Add description */
	bool propGetDynamicValue(const std::string& name,
			DynamicValue& value) const;

	/* TODO: Add description */
	template<typename T>
	T propGet(const std::string& name) const;

	/* TODO: Add description */
	template<typename T>
	T propGetDefault(const std::string& name, const T& defValue) const;

	/* TODO: Add description */
	template<typename T>
	bool propGet(const std::string& name, T& value) const;


	/* TODO: Add description */
	size_t propImportLocal(const PropertyNode& properties,
			const std::string& prefix = "", bool override = true);

	/* TODO: Add description */
	inline void propClear() {

		properties_.clear();
	}

	/* TODO: Add description */
	void propPrintLocal() const;


	/* TODO: Add description */
	std::string propGetAsText() const;


	/* TODO: Add description */
	inline const map_type_t& propGetLocal() const {

		return properties_;
	}


	/* TODO: Add description */
	virtual ~PropertyNode();

};

#endif
