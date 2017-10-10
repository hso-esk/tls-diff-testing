#ifndef __DequeRingBuffer_H__
#define __DequeRingBuffer_H__

#include <stdint.h>
#include <deque>
#include "RingBuffer.h"


/* ==========================================================================
 *
 * ---------------------------------
 * | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 * ---------------------------------
 *
 * ========================================================================== */

class DequeRingBuffer : public RingBuffer {

private:

	/* TODO: Add description */
	std::deque<uint8_t>	data_;

	/* TODO: Add description */
	uint8_t writeBitOff_;

	/* TODO: Add description */
	uint8_t readBitOff_;


protected:

	/* --- from RingBuffer -> StreamReader -> BufferReader class: ---------- */

	/* TODO: Add description */
	virtual bool getBit_(const BC& bc) const;

	/* TODO: Add description */
	virtual uint8_t getByte_(const BC& bc) const;

	/* TODO: Add description */
	virtual BC copyTo_(BufferWriter& buffer) const;

	/* TODO: Add description */
	virtual BC getLength_() const;

	/* --- from RingBuffer -> StreamReader class: -------------------------- */

	/* TODO: Add description */
	virtual uint8_t readByte_(bool remove = true);

	/* TODO: Add description */
	virtual bool readBit_(bool remove = true);

	/* --- from RingBuffer class: ------------------------------------------ */

	/* TODO: Add description */
	virtual void clear_();

	/* --------------------------------------------------------------------- */


public:

	/* TODO: Add description */
	DequeRingBuffer();

	/* TODO: Add description */
	DequeRingBuffer(const BC& capacity);

	/* --- from RingBuffer -> BufferWriter class: -------------------------- */

	/* TODO: Add description */
	virtual bool appendBit(bool bit);

	/* TODO: Add description */
	virtual bool appendByte(uint8_t byte);

	/* TODO: Add description */
	virtual bool setBit(const BC& bc, bool bit);

	/* TODO: Add description */
	virtual bool setByte(const BC& bc, uint8_t byte);

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual ~DequeRingBuffer();

};

#endif
