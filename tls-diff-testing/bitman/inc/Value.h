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
