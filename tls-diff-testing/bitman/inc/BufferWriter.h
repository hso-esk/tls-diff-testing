#ifndef __BufferWriter_H__
#define __BufferWriter_H__

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "BC.h"

class String;
class BufferReader;
class StreamReader;


/* ==========================================================================
 *
 * Inheriting classes need to implement:
 *
 *
 * ========================================================================== */

class BufferWriter {

private:

	/* TODO: Add description */
	static int convertDigit(char c, size_t base);


public:

	/* TODO: Add description */
	BufferWriter();

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual bool appendBit(bool bit) = 0;

	/* TODO: Add description */
	virtual bool appendByte(uint8_t byte) = 0;

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	BC appendBits(const bool* const bits, size_t max);

	/* TODO: Add description */
	BC appendBytes(const uint8_t* const bytes, size_t max);

	/* TODO: Add description */
	BC appendFromBuffer(const BufferReader& reader, BC max = -1);

	/* TODO: Add description */
	BC appendFromString(const std::string& str, BC max = -1);

	/* TODO: Add description */
	BC appendFromBitString(const std::string& str, const BC& max = -1);

	/* TODO: Add description */
	BC appendFromHexString(const std::string& str, const BC& max = -1);

	/* TODO: Add description */
	BC appendFromBase64String(const std::string& str, const BC& max = -1);

	/* TODO: Add description */
	BC appendFromAsciiString(const std::string& str, const BC& max = -1);

	/* TODO: Add description */
	BC appendFromFile(const std::string& filename);

	/* TODO: Add description */
	BC appendFromHexFile(const std::string& filename);


	/* TODO: Add description */
	BC consumeStream(StreamReader& reader, BC max = -1);

	/* TODO: Add description */
	BC consumeBitString(std::string& str, BC max = -1);

	/* TODO: Add description */
	BC consumeHexString(std::string& str, BC max = -1);

	/* TODO: Add description */
	BC consumeBase64String(std::string& str, BC max = -1);

	/* TODO: Add description */
	BC consumeAsciiString(std::string& str, BC max = -1);


	/* TODO: Add description */
	BufferWriter& operator<<(const std::string& str);


	/* TODO: Add description */
	BC appendNumberBits(size_t number, size_t nBits,
			bool bigEndian = true, BC max = -1);

	/* TODO: Add description */
	BC appendDigitBits(char c, size_t base, bool bigEndian = true, BC max = -1);


	/* TODO: Add description */
	virtual ~BufferWriter();

};

#endif
