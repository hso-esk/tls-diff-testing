#ifndef __BufferReader_H__
#define __BufferReader_H__

#include <string>
#include <vector>
#include "BC.h"

class String;
class BufferWriter;
class BufferWindowReader;


/* =========================================================================
 *
 *
 *
 * ========================================================================= */

class BufferReader {

protected:

	/* === To be implemented by sub-classes: =============================== */

	/* TODO: Add description */
	virtual bool getBit_(const BC& bc) const = 0;

	/* TODO: Add description */
	virtual uint8_t getByte_(const BC& bc) const = 0;

	/* TODO: Add description */
	virtual BC copyTo_(BufferWriter& buffer) const = 0;

	/* TODO: Add description */
	virtual BC getLength_() const = 0;

	/* ===================================================================== */


public:

	/* TODO: Add description */
	BufferReader();


	/* TODO: Add description */
	inline bool getBit(const BC& bc) const {

		return this->getBit_(bc);
	}

	/* TODO: Add description */
	inline uint8_t getByte(const BC& bc) const {

		return this->getByte_(bc);
	}

	/* TODO: Add description */
	inline BC copyTo(BufferWriter& buffer) const {

		return this->copyTo_(buffer);
	}

	/* TODO: Add description */
    BC copyTo(uint8_t* const bytes, size_t max) const;

	/* TODO: Add description */
	inline BC getLength() const {

		return this->getLength_();
	}

	/* TODO: Add description */
	inline bool isEmpty() const {

		return (this->getLength() == 0);
	}


	/* TODO: Add description */
	uint8_t getBytePadded(BC bc, bool padLeft = false) const;


	/* TODO: Add description */
	BufferWindowReader getWindow(BC offset = 0, BC length = -1) const;


	/* TODO: Add description */
	String toBitString(bool split = false, BC from = -1, BC len = -1) const;

	/* TODO: Add description */
	String toHexString(bool split = false, BC from = -1, BC len = -1, bool markMisaligned = false) const;

	/* TODO: Add description */
	std::string toBase64String() const;

	/* TODO: Add description */
	String toRawString(size_t cols = 16, BC from = -1, BC len = -1) const;

	/* TODO: Add description */
	String toCString(size_t cols = 16, BC from = -1, BC len = -1) const;


	/* TODO: Add description */
	size_t printBitDump(BC from = -1, BC len = -1) const;

	/* TODO: Add description */
	void printHexDump(size_t nCols = 16) const;

	/* TODO: Add description */
	std::string getHexDump(size_t nCols = 16) const;


	/* TODO: Add description */
	BC exportToFile(const std::string& filename) const;


	/* TODO: Add description */
	bool isEqualTo(const BufferReader& reader) const;


	/* TODO: Add description */
	bool operator==(const BufferReader& reader) const {

		return this->isEqualTo(reader);
	}


	/* TODO: Add description */
	virtual ~BufferReader();

};

#endif
