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
