#ifndef __StreamStreamReader_H__
#define __StreamStreamReader_H__

#include "BC.h"
#include "StreamReader.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class StreamStreamReader : public StreamReader {

private:

	/* TODO: Add description */
	BC len_;

	/* TODO: Add description */
	StreamReader& reader_;

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
	StreamStreamReader(StreamReader& reader);

	/* TODO: Add description */
	StreamStreamReader(StreamReader& reader, const BC& len);


	/* TODO: Add description */
	virtual ~StreamStreamReader();

};

#endif
