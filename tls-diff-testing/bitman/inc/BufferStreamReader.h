#ifndef __BufferStreamReader_H__
#define __BufferStreamReader_H__

#include "BC.h"
#include "String_.h"
#include "Buffer.h"
#include "StreamReader.h"


/* =========================================================================
 *
 *
 *
 * ========================================================================= */

class BufferStreamReader : public StreamReader {

private:

	/* TODO: Add description */
	const BufferReader&	reader_;

	/* TODO: Add description */
	BC pos_;


protected:

	/* --- from StreamReader class: ---------------------------------------- */

	/* TODO: Add description */
	virtual uint8_t readByte_(bool remove = true);

	/* TODO: Add description */
	virtual bool readBit_(bool remove = true);

	/* --- from StreamReader -> BufferReader class: ------------------------ */

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
	BufferStreamReader(const BufferReader& reader);


	/* TODO: Add description */
	inline void reset() {

		pos_ = 0;
	}

	/* TODO: Add description */
	inline void setPosition(const BC& pos) {

		/* don't change 'pos_' if 'pos' is undefined */
		pos_ = pos.isDef() ? pos : pos_;
	}

	/* TODO: Add description */
	inline BC getPosition() const {

		return pos_;
	}


	/* TODO: Add description */
	virtual ~BufferStreamReader();

};

#endif
