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

