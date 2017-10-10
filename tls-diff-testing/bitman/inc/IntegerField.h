#ifndef __IntegerField_H__
#define __IntegerField_H__

#include <string>
#include <vector>
#include <inttypes.h>

#include "FieldDataUnit.h"


class IntegerField : public FieldDataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


protected:

	/* TODO: Add description */
	static size_t getBitWeight(size_t bit, size_t size,
    		bool bigEndianBytes_ = true, bool bigEndianBits_ = true);


	/* TODO: Add description */
    bool isSigned_;

    /* TODO: Add description */
    bool bigEndianBytes_;

    /* TODO: Add description */
    bool bigEndianBits_;

    /* TODO: Add description */
    int value_;

    /* TODO: Add description */
    bool decoded_;


	/* --- from PropertyNode class: ---------------------------------------- */

	/* TODO: Add description */
    virtual void propReadHook_(const std::string& name, DynamicValue& value) const;

	/* TODO: Add description */
	virtual void propWriteHook_(const std::string& name, DynamicValue& value);

	/* --- from FieldDataUnit class: --------------------------------------- */

	/* TODO: Add description */
	virtual bool decode_(const BufferReader& reader);

	/* TODO: Add description */
	virtual bool encode_();

	/* --- from DataUnit class: -------------------------------------------- */

	/* TODO: Add description */
	virtual bool isDecoded_() const;

	/* TODO: Add description */
	virtual DataUnit* newInstance_() const;

	/* --------------------------------------------------------------------- */

    /* TODO: Add description */
	virtual std::string getInfo_() const;


public:

    /* TODO: Add description */
	static IntegerField* newIntBE(size_t bitWidth);

    /* TODO: Add description */
	static IntegerField* newUIntBE(size_t bitWidth);

    /* TODO: Add description */
	static IntegerField* newIntLE(size_t bitWidth);

    /* TODO: Add description */
	static IntegerField* newUIntLE(size_t bitWidth);


	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: implement min / max */

    /* TODO: Add description */
    IntegerField(const BC& size, bool isSigned = false,
    		bool bigEndianBytes = true, bool bigEndianBits = true);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


    /* TODO: Add description */
	bool isSigned() const;


    /* TODO: Add description */
	template<typename T>
	T getValue() const;

    /* TODO: Add description */
	void setValue(int value);


    /* TODO: Add description */
	virtual ~IntegerField();

};

#endif
