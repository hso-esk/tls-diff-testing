#ifndef __DataUnitFragment_H__
#define __DataUnitFragment_H__

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "DataUnit.h"

class DataUnitStream;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DataUnitFragment : public DataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


	/* TODO: Add description */
	DataUnitStream& protocol_;

	/* TODO: Add description */
	BC offset_;

	/* TODO: Add description */
	BC len_;


protected:

	/* TODO: Add description */
	virtual void printBody(const PrintOptions& options) const;

	/* --- from DataUnit -> ProtocolDissector class: ----------------------- */

	/* TODO: Add description */
	virtual void dissectorBodyReset();

	/* TODO: Add description */
	virtual bool dissectorBodyIsAccepting() const;

	/* TODO: Add description */
	virtual BC dissectorBodyDissect(StreamReader& reader);

	/* --------------------------------------------------------------------- */

	/* --- from DataUnit -> BufferReader class: ---------------------------- */

	/* TODO: Add description */
	virtual bool getBit_(const BC& bc) const;

	/* TODO: Add description */
	virtual uint8_t getByte_(const BC& bc) const;

	/* TODO: Add description */
	virtual BC copyTo_(BufferWriter& buffer) const;

	/* TODO: Add description */
	virtual BC getLength_() const;

	/* --- from DataUnit class: -------------------------------------------- */

	/* TODO: Add description */
	virtual bool isDecoded_() const;

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual std::string	getAnchorBrackets_() const;


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	DataUnitFragment(DataUnitStream& protocol, const BC& size = -1);


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;

	/* --- from DataUnit -> BufferWriter class: ---------------------------- */

	/* TODO: Add description */
	virtual bool appendBit(bool bit);

	/* TODO: Add description */
	virtual bool appendByte(uint8_t byte);

	/* --- from DataUnit -> BufferModifier class: -------------------------- */

	/* TODO: Add description */
	virtual bool setBit(const BC& bc, bool bit);

	/* TODO: Add description */
	virtual bool setByte(const BC& bc, uint8_t byte);

	/* TODO: Add description */
	virtual void clear();

	/* TODO: Add description */
	virtual void truncate(const BC& length);

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual ~DataUnitFragment();

};

#endif
