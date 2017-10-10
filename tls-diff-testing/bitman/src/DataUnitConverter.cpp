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

#include "DataUnitConverter.h"
#include <string>
#include "String_.h"
#include "FieldDataUnit.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
DataUnitConverter::DataUnitConverter(const DataUnit& dataUnit)
		: dataUnit_(dataUnit) {
}


/*
 * ___________________________________________________________________________
 */
string DataUnitConverter::getAsJSON() const {

	return this->getAsJSON_(dataUnit_);
}


/*
 * ___________________________________________________________________________
 */
string DataUnitConverter::getAsJSON_(const DataUnit& dataUnit) const {

	String json;

	json.appendFormat("\"__refname__\": \"%s\",\n",
			dataUnit.getRefName().c_str());
	json.appendFormat("\"__type__\": \"%s\",\n",
			dataUnit.getTypeName().c_str());

	if (dataUnit.containsType(FieldDataUnit::typeDescriptor())) {
		json.appendFormat("\"__data__\": \"%s\",\n",
				dataUnit.toHexString().c_str());
	} else if (dataUnit.hasChild()) {

		String children;

		DataUnit* child = dataUnit.getChild();
		while (child != 0) {
			children.append(this->getAsJSON_(*child));
			child = child->getNext();
			if (child != 0) {
				children.append(",");
			}
			children.append("\n");
		}

		children.indentLines("  ");
		children.prepend("\"__data__\": [\n");
		children.append("]\n");
		json.append(children);
	}

	json.indentLines("  ");
	json.prepend("{\n");
	json.append("}");

	return json;
}


/*
 * ___________________________________________________________________________
 */
DataUnitConverter::~DataUnitConverter() {
}

