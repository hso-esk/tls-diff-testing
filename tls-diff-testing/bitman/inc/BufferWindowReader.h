#ifndef __BufferWindowReader_H__
#define __BufferWindowReader_H__

#include "BC.h"
#include "BufferReader.h"


/* =========================================================================
 *
 *
 *
 * ========================================================================= */

class BufferWindowReader : public BufferReader {

private:

	/* TODO: Add description */
	const BufferReader&	reader_;

	/* TODO: Add description */
	BC offset_;

	/* TODO: Add description */
	BC length_;


protected:

	/* --- from BufferReader class: ---------------------------------------- */

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
	BufferWindowReader(const BufferReader& reader,
			BC offset = 0, BC length = -1);


	/* TODO: Add description */
	virtual ~BufferWindowReader();

};

#endif
