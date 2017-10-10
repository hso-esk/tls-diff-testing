#ifndef __HMAC_H__
#define __HMAC_H__

#include <stdlib.h>
#include <stdio.h>
#include "MessageDigest.h"
#include "VectorBuffer.h"

class BufferWriter;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class HMAC : public MessageDigest {

private:

	MessageDigest*	digest_;
	VectorBuffer	key_;

	void initDigest();


public:

	HMAC(MessageDigest* digest, const BufferReader& key);

	virtual const BC&	getDigestSize() const;
	virtual const BC&	getBlockSize() const;

	virtual void 	reset();
	virtual void 	update(const BufferReader& message);
	virtual void 	finish(BufferWriter& hash);

	virtual ~HMAC();

};

#endif
