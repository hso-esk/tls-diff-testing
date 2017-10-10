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

#include <stdexcept>
#include <vector>
#include <iostream>
#include "EnumerationField.h"
#include "String_.h"
#include "Value.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;


/*
 * ___________________________________________________________________________
 */
EnumerationItem::EnumerationItem(const std::string& name, int code) :
		name_(name), minCode_(code), maxCode_(code) {
}


/*
 * ___________________________________________________________________________
 */
EnumerationItem::EnumerationItem(const std::string& name,
		int minCode, int maxCode) : name_(name) {

	if (minCode <= maxCode) {
		minCode_ = minCode;
		maxCode_ = maxCode;
	} else {
		// Resolve minCode > maxCode --> swap
		minCode_ = maxCode;
		maxCode_ = minCode;
	}
}


/*
 * ___________________________________________________________________________
 */
bool EnumerationItem::overlapsWith(const EnumerationItem& item) const {

	/* there is an overlap if either side (min or max) of
	 * one item overlaps with the range of the other item */
	return this->matchesCode(item.getMinCode())
		|| this->matchesCode(item.getMaxCode());
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
EnumerationItemList::EnumerationItemList() : allowFallback_(false) {
}


/*
 * ___________________________________________________________________________
 */
bool EnumerationItemList::addItem(const std::string& name, int code) {

	EnumerationItem item(name, code);
	return this->insertItem(item);
}


/*
 * ___________________________________________________________________________
 */
bool EnumerationItemList::addItem(const std::string& name,
		int minCode, int maxCode) {

	EnumerationItem item(name, minCode, maxCode);
	return this->insertItem(item);
}


/*
 * ___________________________________________________________________________
 */
bool EnumerationItemList::addFallbackItem(const std::string& name) {

	bool success = false;

	/* cannot have more than one fallback item */
	if (!allowFallback_) {
		allowFallback_ = true;
		fallbackItemName_ = name;
		success = true;
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
bool EnumerationItemList::overlapsWith(const EnumerationItem& item) const {

	bool overlaps = false;
	for (size_t i = 0; i < items_.size(); ++i && !overlaps) {
		if (items_[i].overlapsWith(item)) {
			overlaps = true;
		}
	}
	return overlaps;
}


/*
 * ___________________________________________________________________________
 */
bool EnumerationItemList::insertItem(const EnumerationItem& item) {

	bool success = false;

	/* TODO: reject if fallback item already present */

	/* accept item if there is no overlap with already present items */
	if (!this->overlapsWith(item)) {
		size_t i = 0;
		/* TODO: use binary search */
		while (i < items_.size()
				&& item.getMinCode() >= items_[i].getMinCode()) {
			i++;
		}
		items_.insert(items_.begin() + i, item);
		success = true;
	}

	return success;
}


/*
 * ___________________________________________________________________________
 */
int EnumerationItemList::getNItems() const {

	return items_.size();
}


/*
 * ___________________________________________________________________________
 */
int EnumerationItemList::getItemIndex(int code) const {

	const EnumerationItem* item = (EnumerationItem*)0;
	bool found = false;

	size_t i;
	size_t l = 0;
	size_t r = items_.size();

	while (l < r && !found) {

		i = l + (r - l) / 2;
		item = &(items_.at(i));

		if (item->matchesCode(code)) {
			found = true;
		} else {
			if (item->getMinCode() < code) {
				l = i + 1;
			} else {
				r = i;
			}
		}
	}

	int index = i;

	if (!found) {
		if (allowFallback_) {
			index = items_.size();
		} else {
			index = -1;
		}
	}

	return index;
}


/*
 * ___________________________________________________________________________
 */
const EnumerationItem& EnumerationItemList::getItemByIndex(int index) const {

	if (index >= 0 && (size_t)index < items_.size()) {
		return items_.at(index);
	} else {
		throw std::runtime_error("EnumerationItemList::getItemByIndex(...):"
				" Item index out of range");
	}
}


/*
 * ___________________________________________________________________________
 */
const string& EnumerationItemList::getItemNameByIndex(int index) const {

	const string* name;

	if (index >= 0 && (size_t)index < items_.size()) {
		/* index refers to an ordinary enum item */
		name = &(items_.at(index).getName());
	} else if (index >= 0 && (size_t)index == items_.size() && allowFallback_) {
		/* index refers to the fallback item */
		name = &fallbackItemName_;
	} else {
		throw std::runtime_error("EnumerationItemList::getItemNameByIndex(...):"
				" Item index out of range");
	}

	return *name;
}


/*
 * ===========================================================================
 */


/*
 * ___________________________________________________________________________
 */
TypeDescriptor EnumerationField::desc_(
		IntegerField::typeDescriptor(), 0, "EnumerationField");


/*
 * ___________________________________________________________________________
 */
EnumerationField::EnumerationField(const BC& size, EnumerationItemList& list) :
		IntegerField(size), list_(list), itemIndex_(-1) {
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& EnumerationField::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
string EnumerationField::getInfo_() const {

	string info;

	if (itemIndex_ >= 0) {
		info = String::format("%s (%u)",
				list_.getItemNameByIndex(itemIndex_).c_str(),
				this->getValue<int>());
	}

	return info;
}


/*
 * ___________________________________________________________________________
 */
const string& EnumerationField::getItemName() const {

	if (itemIndex_ >= 0) {
		return list_.getItemNameByIndex(itemIndex_);
	} else {
		static string empty;
		return empty;
	}
}


/*
 * ___________________________________________________________________________
 */
bool EnumerationField::isDecoded_() const {

	return itemIndex_ >= 0;
}


/*
 * ___________________________________________________________________________
 */
bool EnumerationField::decode_(const BufferReader& reader) {

	itemIndex_ = -1;

	if (IntegerField::decode_(reader)) {
		itemIndex_ = list_.getItemIndex(this->getValue<int>());
	}

	return itemIndex_ >= 0;
}


/*
 * ___________________________________________________________________________
 */
std::string EnumerationField::getDynamicTypeName_() const {

	return this->getItemName();
}


/*
 * ___________________________________________________________________________
 */
void EnumerationField::propReadHook_(const string& name, DynamicValue& value) const {

	if (itemIndex_ >= 0 && name == ".name") {
		value.setValue<string>(list_.getItemNameByIndex(itemIndex_));
	} else if (name == ".index") {
		value.setValue<int>(itemIndex_);
	} else {
		/* process base class hook */
		IntegerField::propReadHook_(name, value);
	}
}


/*
 * ___________________________________________________________________________
 */
void EnumerationField::propWriteHook_(const string& name, DynamicValue& value) {

	if (name == ".value") {
		itemIndex_ = list_.getItemIndex(value.getValue<int>());
	}
	/* process base class hook */
	IntegerField::propWriteHook_(name, value);
}


/*
 * ___________________________________________________________________________
 */
EnumerationField::~EnumerationField() {
}

