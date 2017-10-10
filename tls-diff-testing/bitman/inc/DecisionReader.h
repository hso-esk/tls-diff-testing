#ifndef __DecisionReader_H__
#define __DecisionReader_H__

#include "StreamReader.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DecisionReader : public StreamReader {

private:

	/* TODO: Add description */
	StreamReader& streamer_;


protected:

	/* --- from StreamReader class: ---------------------------------------- */

	/* TODO: Add description */
	inline uint8_t readByte_(bool remove = true) {

		return streamer_.readByte(remove);
	}

	/* TODO: Add description */
	inline bool readBit_(bool remove = true) {

		return streamer_.readBit(remove);
	}

	/* --- from StreamReader -> BufferReader class: ------------------------ */

	/* TODO: Add description */
	inline bool getBit_(const BC& bc) const {

		return streamer_.getBit(bc);
	}

	/* TODO: Add description */
	inline uint8_t getByte_(const BC& bc) const {

		return streamer_.getByte(bc);
	}

	/* TODO: Add description */
	inline BC copyTo_(BufferWriter& buffer) const {

		return streamer_.copyTo(buffer);
	}

	/* TODO: Add description */
	inline BC getLength_() const {

		return streamer_.getLength();
	}

	/* --------------------------------------------------------------------- */


public:

	/* TODO: Add description */
	DecisionReader(StreamReader& streamer);


	inline StreamReader& getStreamReader() {

		return streamer_;
	}


	/* TODO: Add description */
	bool readBoolUniform();

	/* TODO: Add description */
	size_t	readUIntUniform(size_t max);

	/* TODO: Add description */
	size_t	readUIntExponential(size_t num, size_t denom);


	/* TODO: Add description */
	virtual ~DecisionReader();

};

#endif
