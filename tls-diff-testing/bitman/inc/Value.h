#ifndef __Value_H__
#define __Value_H__

#include <string>

class ValueBase;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DynamicValue {

private:

	/* TODO: Add description */
	ValueBase* value_;

	/* TODO: Add description */
	const ValueBase& getValueObject() const;


public:

	/* TODO: Add description */
	DynamicValue();

	/* TODO: Add description */
	DynamicValue(const DynamicValue& value);


	/* TODO: Add description */
	inline bool isDef() const {

		return (value_ != 0);
	}

	/* TODO: Add description */
	inline bool isUndef() const {

		return (value_ == 0);
	}

	/* TODO: Add description */
	void setUndef();


	/* TODO: Add description */
	DynamicValue* getCopy() const;


	/* TODO: Add description */
	template<typename T>
	T getValue() const;

	/* TODO: Add description */
	template<typename T>
	bool setValue(const T& value);


	/* TODO: Add description */
	DynamicValue& operator=(const DynamicValue& value);


	/* TODO: Add description */
	virtual ~DynamicValue();

};


/* ==========================================================================
 *
 *
 * ========================================================================== */

class ValueBase {

public:

	/* TODO: Add description */
	ValueBase();

	/* === To be implemented by sub-classes: =============================== */

	/* TODO: Add description */
	virtual ValueBase* getCopy() const = 0;


	/* TODO: Add description */
	virtual int getInt() const = 0;

	/* TODO: Add description */
	virtual bool getBool() const = 0;

	/* TODO: Add description */
	virtual double getDouble() const = 0;

	/* TODO: Add description */
	virtual std::string getString() const = 0;

	/* ===================================================================== */

	/* TODO: Add description */
	virtual ~ValueBase();

};


/* ==========================================================================
 *
 *
 * ========================================================================== */

class IntValue : public ValueBase {

private:

	/* TODO: Add description */
	int	value_;


	/* TODO: Add description */
	IntValue();

	/* TODO: Add description */
	IntValue(int value);

	/* TODO: Add description */
	IntValue(const IntValue& value);


public:

	/* TODO: Add description */
	static inline IntValue* newIntValue(int value) {

		return new IntValue(value);
	}


	/* TODO: Add description */
	virtual IntValue* getCopy() const;


	/* TODO: Add description */
	virtual int getInt() const;

	/* TODO: Add description */
	virtual bool getBool() const;

	/* TODO: Add description */
	virtual double getDouble() const;

	/* TODO: Add description */
	virtual std::string	getString() const;


	/* TODO: Add description */
	virtual ~IntValue();

};


/* ==========================================================================
 *
 *
 * ========================================================================== */

class BoolValue : public ValueBase {

private:

	/* TODO: Add description */
	bool value_;


	/* TODO: Add description */
	BoolValue();

	/* TODO: Add description */
	BoolValue(bool value);

	/* TODO: Add description */
	BoolValue(const BoolValue& value);


public:

	/* TODO: Add description */
	static inline BoolValue* newBoolValue(bool value) {

		return new BoolValue(value);
	}


	/* TODO: Add description */
	virtual BoolValue* getCopy() const;


	/* TODO: Add description */
	virtual int getInt() const;

	/* TODO: Add description */
	virtual bool getBool() const;

	/* TODO: Add description */
	virtual double getDouble() const;

	/* TODO: Add description */
	virtual std::string	getString() const;


	/* TODO: Add description */
	virtual ~BoolValue();

};


/* ==========================================================================
 *
 *
 * ========================================================================== */

class DoubleValue : public ValueBase {

private:

	/* TODO: Add description */
	double value_;


	/* TODO: Add description */
	DoubleValue();

	/* TODO: Add description */
	DoubleValue(double value);

	/* TODO: Add description */
	DoubleValue(const DoubleValue& value);


public:

	/* TODO: Add description */
	static inline DoubleValue* newDoubleValue(double value) {

		return new DoubleValue(value);
	}


	/* TODO: Add description */
	virtual DoubleValue* getCopy() const;


	/* TODO: Add description */
	virtual int getInt() const;

	/* TODO: Add description */
	virtual bool getBool() const;

	/* TODO: Add description */
	virtual double getDouble() const;

	/* TODO: Add description */
	virtual std::string	getString() const;


	/* TODO: Add description */
	virtual ~DoubleValue();

};


/* ==========================================================================
 *
 *
 * ========================================================================== */

class StringValue : public ValueBase {

private:

	/* TODO: Add description */
	std::string	value_;


	/* TODO: Add description */
	StringValue();

	/* TODO: Add description */
	StringValue(const std::string& value);

	/* TODO: Add description */
	StringValue(const StringValue& value);


public:

	/* TODO: Add description */
	static inline StringValue* newStringValue(const std::string& value) {

		return new StringValue(value);
	}


	/* TODO: Add description */
	virtual StringValue* getCopy() const;


	/* TODO: Add description */
	virtual int getInt() const;

	/* TODO: Add description */
	virtual bool getBool() const;

	/* TODO: Add description */
	virtual double getDouble() const;

	/* TODO: Add description */
	virtual std::string	getString() const;


	/* TODO: Add description */
	virtual ~StringValue();

};

#endif
