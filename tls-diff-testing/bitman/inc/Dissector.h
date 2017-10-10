#ifndef __ProtocolDissector_H__
#define __ProtocolDissector_H__

#include <stdexcept>
#include "BC.h"
#include "StreamStreamReader.h"

class BufferReader;
class StreamReader;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DissectionError : public std::runtime_error {

public:

	DissectionError(const std::string& error) : std::runtime_error(error) {
	}

};


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class DissectorBody {

public:

	/* TODO: Add description */
	virtual void dissectorBodyReset() = 0;

	/* TODO: Add description */
	virtual bool dissectorBodyIsAccepting() const = 0;

	/* TODO: Add description */
	virtual BC dissectorBodyDissect(StreamReader& reader) = 0;

};


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class Dissector {

private:

	/* the dissector body */
	DissectorBody& body_;

	/* the externally defined size of the dissector */
	BC size_;

	/* the total amount of data consumed by the dissector */
	BC length_;

	/* the amount of overflow data discarded by the dissector */
	BC overflow_;

	/* true if dissector has been closed */
	bool closed_;

	/* TODO: Add description */
	StreamStreamReader* reader_;


public:

	/* TODO: Add description */
	Dissector(DissectorBody& body);


	/* TODO: Add description */
	BC reset();

	/* TODO: Add description */
	BC reset(const BC& size);


	/* TODO: Add description */
	inline void close() {

		closed_ = true;
	}


	/* TODO: Add description */
	void setSize(const BC& size);

	/* TODO: Add description */
	inline const BC& getSize() const {

		return size_;
	}


	/* TODO: Add description */
	inline BC getLength() const {

		return length_ + ((reader_ != 0) ? reader_->getAccumulator() : 0);
	}

	/* TODO: Add description */
	inline BC getAcceptance() const {

		/* returns an undefined value if size_ is undefined */
		return closed_ ? 0 : size_ - this->getLength();
	}


	/* TODO: Add description */
	bool isAccepting() const;


	/* TODO: Add description */
	inline BC getOverflow() const {

		return overflow_;
	}

	/* TODO: Add description */
	inline bool hasOverflow() const {

		/* excess_ is never undefined */
		return overflow_ > 0;
	}

	/* TODO: Add description */
	inline bool hasUnderflow() const {

        /* TODO: use just "body_.dissectorBodyIsAccepting()"? */
		return this->getAcceptance() == 0 && body_.dissectorBodyIsAccepting();
	}


	/* TODO: Add description */
	BC dissect(StreamReader& reader, const BC& max = -1);

	/* TODO: Add description */
	BC dissectFromBuffer(const BufferReader& reader, const BC& max = -1);


	/* TODO: Add description */
	virtual ~Dissector();

};

#endif
