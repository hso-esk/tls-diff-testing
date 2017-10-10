#ifndef __StreamReader_H__
#define __StreamReader_H__

#include "BufferReader.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class StreamReader : public BufferReader {

private:

	/* TODO: Add description */
	BC accu_;


protected:

	/* === To be implemented by sub-classes: =============================== */

	/* TODO: Add description */
	virtual uint8_t readByte_(bool remove = true) = 0;

	/* TODO: Add description */
	virtual bool readBit_(bool remove = true) = 0;

	/* ===================================================================== */


public:

	/* TODO: Add description */
	StreamReader();

	/* TODO: Add description */
	uint8_t readByte(bool remove = true);

	/* TODO: Add description */
	bool readBit(bool remove = true);


	/* TODO: Add description */
	BC flush(const BC& max = -1);


	/* TODO: Add description */
	inline const BC& getAccumulator() const {

		return accu_;
	}

	/* TODO: Add description */
	inline void resetAccumulator() {

		accu_ = 0;
	}

	virtual ~StreamReader();

};

#endif
