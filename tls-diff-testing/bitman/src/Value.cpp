#include <stdexcept>
#include "Value.h"
#include "String_.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
ValueBase::ValueBase() {
}


/*
 * ___________________________________________________________________________
 */
ValueBase::~ValueBase() {
}


/* ========================================================================= */


/*
 * ___________________________________________________________________________
 */
DynamicValue::DynamicValue() : value_(0) {
}


/*
 * ___________________________________________________________________________
 */
DynamicValue::DynamicValue(const DynamicValue& value) {

	if (value.isDef()) {
		value_ = value.getValueObject().getCopy();
	} else {
		value_ = (ValueBase*)0;
	}
}


/*
 * ___________________________________________________________________________
 */
void DynamicValue::setUndef() {

	if (value_ != 0) {
		delete value_;
		value_ = 0;
	}
}


/*
 * ___________________________________________________________________________
 */
DynamicValue* DynamicValue::getCopy() const {

	DynamicValue* copy;
	if (value_ != 0) {
		copy = new DynamicValue(*this);
	} else {
		copy = new DynamicValue();
	}
	return copy;
}


/*
 * ___________________________________________________________________________
 */
const ValueBase& DynamicValue::getValueObject() const {

	if (value_ != 0) {
		return *value_;
	} else {
		throw std::runtime_error("Value::getValueObject(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
template<>
int DynamicValue::getValue() const {

	if (value_ != 0) {
		return value_->getInt();
	} else {
		throw std::runtime_error("Value::getValue<int>(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
template<>
bool DynamicValue::getValue() const {

	if (value_ != 0) {
		return value_->getBool();
	} else {
		throw std::runtime_error("Value::getValue<bool>(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
template<>
double DynamicValue::getValue() const {

	if (value_ != 0) {
		return value_->getDouble();
	} else {
		throw std::runtime_error("Value::getValue<double>(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
template<>
string DynamicValue::getValue() const {

	if (value_ != 0) {
		return value_->getString();
	} else {
		throw std::runtime_error("Value::getValue<string>(): Value undefined");
	}
}


/*
 * ___________________________________________________________________________
 */
template<>
bool DynamicValue::setValue(const int& value) {

	this->setUndef();
	value_ = IntValue::newIntValue(value);
	return true;
}


/*
 * ___________________________________________________________________________
 */
template<>
bool DynamicValue::setValue(const bool& value) {

	this->setUndef();
	value_ = BoolValue::newBoolValue(value);
	return true;
}


/*
 * ___________________________________________________________________________
 */
template<>
bool DynamicValue::setValue(const double& value) {

	this->setUndef();
	value_ = DoubleValue::newDoubleValue(value);
	return true;
}


/*
 * ___________________________________________________________________________
 */
template<>
bool DynamicValue::setValue(const string& value) {

	this->setUndef();
	value_ = StringValue::newStringValue(value);
	return true;
}


/*
 * ___________________________________________________________________________
 */
DynamicValue& DynamicValue::operator=(const DynamicValue& value) {

	this->setUndef();

	if (value.isDef()) {
		value_ = value.getValueObject().getCopy();
	}

	return *this;
}


/*
 * ___________________________________________________________________________
 */
DynamicValue::~DynamicValue() {

	this->setUndef();
}


/* ========================================================================= */


/*
 * ___________________________________________________________________________
 */
IntValue::IntValue() : value_(0) {
}


/*
 * ___________________________________________________________________________
 */
IntValue::IntValue(int value) : value_(value) {
}


/*
 * ___________________________________________________________________________
 */
IntValue::IntValue(const IntValue& value) : value_(value.getInt()) {
}


/*
 * ___________________________________________________________________________
 */
IntValue* IntValue::getCopy() const {

	return new IntValue(*this);
}


/*
 * ___________________________________________________________________________
 */
int IntValue::getInt() const {

	return value_;
}


/*
 * ___________________________________________________________________________
 */
bool IntValue::getBool() const {

	return (value_ != 0);
}


/*
 * ___________________________________________________________________________
 */
double IntValue::getDouble() const {

	return (double)value_;
}


/*
 * ___________________________________________________________________________
 */
string IntValue::getString() const {

	return String::format("%d", value_);
}


/*
 * ___________________________________________________________________________
 */
IntValue::~IntValue() {
}


/* ========================================================================= */


/*
 * ___________________________________________________________________________
 */
BoolValue::BoolValue() : value_(0) {
}


/*
 * ___________________________________________________________________________
 */
BoolValue::BoolValue(bool value) : value_(value) {
}


/*
 * ___________________________________________________________________________
 */
BoolValue::BoolValue(const BoolValue& value) : value_(value.getBool()) {
}


/*
 * ___________________________________________________________________________
 */
BoolValue* BoolValue::getCopy() const {

	return new BoolValue(*this);
}


/*
 * ___________________________________________________________________________
 */
int BoolValue::getInt() const {

	return value_ ? 1 : 0;
}


/*
 * ___________________________________________________________________________
 */
bool BoolValue::getBool() const {

	return value_;
}


/*
 * ___________________________________________________________________________
 */
double BoolValue::getDouble() const {

	return value_ ? 1. : 0.;
}


/*
 * ___________________________________________________________________________
 */
string BoolValue::getString() const {

	string value;
	if (value_) {
		value = "true";
	} else {
		value = "false";
	}
	return value;
}


/*
 * ___________________________________________________________________________
 */
BoolValue::~BoolValue() {
}


/* ========================================================================= */


/*
 * ___________________________________________________________________________
 */
DoubleValue::DoubleValue() : value_(0) {
}


/*
 * ___________________________________________________________________________
 */
DoubleValue::DoubleValue(double value) : value_(value) {
}


/*
 * ___________________________________________________________________________
 */
DoubleValue::DoubleValue(const DoubleValue& value) : value_(value.getDouble()) {
}


/*
 * ___________________________________________________________________________
 */
DoubleValue* DoubleValue::getCopy() const {

	return new DoubleValue(*this);
}


/*
 * ___________________________________________________________________________
 */
int DoubleValue::getInt() const {

	return (int)value_;
}


/*
 * ___________________________________________________________________________
 */
bool DoubleValue::getBool() const {

	return value_ != 0.;
}


/*
 * ___________________________________________________________________________
 */
double DoubleValue::getDouble() const {

	return value_;
}


/*
 * ___________________________________________________________________________
 */
string DoubleValue::getString() const {

	return String::format("%f", value_);
}


/*
 * ___________________________________________________________________________
 */
DoubleValue::~DoubleValue() {
}




/* ========================================================================= */


/*
 * ___________________________________________________________________________
 */
StringValue::StringValue() : value_("") {
}


/*
 * ___________________________________________________________________________
 */
StringValue::StringValue(const string& value) : value_(value) {
}


/*
 * ___________________________________________________________________________
 */
StringValue::StringValue(const StringValue& value) : value_(value.getString()) {
}


/*
 * ___________________________________________________________________________
 */
StringValue* StringValue::getCopy() const {

	return new StringValue(*this);
}


/*
 * ___________________________________________________________________________
 */
int StringValue::getInt() const {

	return -1; /* TODO !! */
}


/*
 * ___________________________________________________________________________
 */
bool StringValue::getBool() const {

	return false; /* TODO !! */
}


/*
 * ___________________________________________________________________________
 */
double StringValue::getDouble() const {

	return false; /* TODO !! */
}


/*
 * ___________________________________________________________________________
 */
string StringValue::getString() const {

	return String(value_);
}


/*
 * ___________________________________________________________________________
 */
StringValue::~StringValue() {
}


