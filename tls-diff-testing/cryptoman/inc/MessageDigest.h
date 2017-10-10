#ifndef __MessageDigest_H__
#define __MessageDigest_H__

#include <stdlib.h>
#include <stdio.h>

class BufferReader;
class BufferWriter;
class BC;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class MessageDigest {

public:

	/* TODO: Add description */
	MessageDigest();

	/* TODO: Add description */
	virtual const BC& getDigestSize() const = 0;

	/* TODO: Add description */
	virtual const BC& getBlockSize() const = 0;


	/* TODO: Add description */
	virtual void reset() = 0;

	/* TODO: Add description */
	virtual void update(const BufferReader& message) = 0;

	/* TODO: Add description */
	virtual void finish(BufferWriter& hash) = 0;


	/* TODO: Add description */
	void digest(const BufferReader& message, BufferWriter& hash);


	/* TODO: Add description */
	virtual ~MessageDigest();

};

#endif
