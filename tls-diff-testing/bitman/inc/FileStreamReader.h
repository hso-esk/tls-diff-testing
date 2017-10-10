#ifndef __FileStreamReader_H__
#define __FileStreamReader_H__

#include <ios>
#include <fstream>
#include <iostream>
#include "BC.h"
#include "String_.h"
#include "Buffer.h"
#include "StreamReader.h"
#include "DequeRingBuffer.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class FileStreamReader : public StreamReader {

private:

	/* TODO: Add description */
	DequeRingBuffer buffer_;


	/* TODO: Add description */
	const std::string& filename_;

	/* TODO: Add description */
	std::ifstream* ifs_;

	/* TODO: Add description */
	BC length_;


	/* TODO: Add description */
	void read_();


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
	FileStreamReader(const std::string& filename, bool infinite = false);


	/* TODO: Add description */
	virtual ~FileStreamReader();

};

#endif
