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

#ifndef __EnumerationField_H__
#define __EnumerationField_H__

#include <string>
#include <vector>
#include "IntegerField.h"

class BufferReader;



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class EnumerationItem {

private:

	/* TODO: Add description */
	std::string name_;

	/* TODO: Add description */
	int minCode_;

	/* TODO: Add description */
	int maxCode_;


public:

	/* TODO: Add description */
	EnumerationItem(const std::string& name, int code);

	/* TODO: Add description */
	EnumerationItem(const std::string& name, int minCode, int maxCode);


	/* TODO: Add description */
	inline const std::string& getName() const {

		return name_;
	}

	/* TODO: Add description */
	inline int getMinCode() const {

		return minCode_;
	}

	/* TODO: Add description */
	inline int getMaxCode() const {

		return maxCode_;
	}


	/* TODO: Add description */
	inline bool isRange() const {

		return (minCode_ != maxCode_);
	}


	/* TODO: Add description */
	inline bool matchesCode(int code) const {

		return (code >= minCode_ && code <= maxCode_);
	}

	/* TODO: Add description */
	bool overlapsWith(const EnumerationItem& item) const;

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class EnumerationItemList {

private:

	/* TODO: Add description */
	std::vector<EnumerationItem> items_;

	/* TODO: Add description */
	bool allowFallback_;

	/* TODO: Add description */
	std::string fallbackItemName_;


	/* TODO: Add description */
	bool overlapsWith(const EnumerationItem& item) const;

	/* TODO: Add description */
	bool insertItem(const EnumerationItem& item);


public:

	/* TODO: Add description */
	EnumerationItemList();


	/* TODO: Add description */
	inline bool allowsFallback() const {

		return allowFallback_;
	}


	/* TODO: Add description */
	bool addItem(const std::string& name, int code);

	/* TODO: Add description */
	bool addItem(const std::string& name, int minCode, int maxCode);

	/* TODO: Add description */
	bool addFallbackItem(const std::string& name = "");


	/* TODO: Add description */
	int getNItems() const;


	/* TODO: Add description */
	int getItemIndex(int code) const;

	/* TODO: Add description */
	const EnumerationItem& getItemByIndex(int index) const;

	/* TODO: Add description */
	const std::string& getItemNameByIndex(int index) const;

};



/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class EnumerationField : public IntegerField {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


	/* TODO: Add description */
	EnumerationItemList& list_;


	/* TODO: Add description */
	int itemIndex_;


protected:

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual std::string	getInfo_() const;

	/* --- from DataUnit class: -------------------------------------------- */

	/* TODO: Add description */
	virtual bool isDecoded_() const;

	/* --- from FieldDataUnit class: --------------------------------------- */

	/* TODO: Add description */
	virtual bool decode_(const BufferReader& reader);

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
    virtual void propReadHook_(const std::string& name, DynamicValue& value) const;

	/* TODO: Add description */
	virtual void propWriteHook_(const std::string& name, DynamicValue& value);

	/* TODO: Add description */
	virtual std::string getDynamicTypeName_() const;

	/* --------------------------------------------------------------------- */


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
    EnumerationField(const BC& size, EnumerationItemList& list);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* TODO: Add description */
	const std::string& getItemName() const;

	/* TODO: Add description */
	inline int getItemIndex() const {

		return itemIndex_;
	}


	/* TODO: Add description */
	inline const EnumerationItemList& getItemList() const {

		return list_;
	}


	/* TODO: Add description */
	virtual ~EnumerationField();

};

#endif
