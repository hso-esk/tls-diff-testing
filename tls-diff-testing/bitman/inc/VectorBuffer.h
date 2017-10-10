#ifndef __VectorBuffer_H__
#define __VectorBuffer_H__

#include <stdlib.h>
#include <stdint.h>
#include "Buffer.h"


/* ==========================================================================
 *
 * ---------------------------------
 * | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 * ---------------------------------
 *
 * ========================================================================== */

class VectorBuffer : public Buffer {

private:

	/* TODO: Add description */
	std::vector<uint8_t> data_;

	/* TODO: Add description */
	uint8_t bitOff_;


	/* TODO: Add description */
	inline bool getBitUnsafe(size_t posByte, size_t posBit) const {

		return (data_[posByte] & (0x80 >> posBit)) != 0;
	}

	/* TODO: Add description */
	inline uint8_t getByteUnsafe(size_t posByte, size_t posBit) const {

		uint8_t val = (data_[posByte] << posBit) & 0xFF;
		if (posBit != 0) {
			val &= (0xFF00 >> (8 - posBit)) & 0xFF;
			val |= (data_[posByte + 1] >> (8 - posBit));
		}
		return val;
	}


protected:

	/* --- from Buffer -> BufferReader class: ------------------------------ */

	/* TODO: Add description */
	virtual bool getBit_(const BC& bc) const;

	/* TODO: Add description */
	virtual uint8_t getByte_(const BC& bc) const;

	/* TODO: Add description */
	virtual BC copyTo_(BufferWriter& buffer) const;

	/* TODO: Add description */
	virtual BC getLength_() const;

	/* --------------------------------------------------------------------- */


public:

	/* TODO: Add description */
	VectorBuffer();

	/* TODO: Add description */
	VectorBuffer(const BC& capacity);

	/* --- from Buffer -> BufferWriter class: ------------------------------ */

	/* TODO: Add description */
	virtual bool appendBit(bool bit);

	/* TODO: Add description */
	virtual bool appendByte(uint8_t byte);

	/* --- from Buffer -> BufferModifier class: ---------------------------- */

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
	const uint8_t* getDataPointer() const;


	virtual ~VectorBuffer();

};

#endif
