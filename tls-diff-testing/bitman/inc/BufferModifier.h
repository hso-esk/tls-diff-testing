#ifndef __BufferModifier_H__
#define __BufferModifier_H__

#include <inttypes.h>

class BC;


/* ==========================================================================
 *
 * Inheriting classes need to implement:
 *
 *
 * ========================================================================== */

class BufferModifier {

public:

	/* TODO: Add description */
	BufferModifier();

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual bool setBit(const BC& bc, bool bit) = 0;

	/* TODO: Add description */
	virtual bool setByte(const BC& bc, uint8_t byte) = 0;

	/* TODO: Add description */
	virtual void clear() = 0;

	/* TODO: Add description */
	virtual void truncate(const BC& length) = 0;

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual ~BufferModifier();

};

#endif
