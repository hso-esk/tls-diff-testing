#ifndef __SHA256_H__
#define __SHA256_H__

#include <stdlib.h>
#include <stdio.h>
#include "MessageDigest.h"
#include "cryptopp/sha.h"

class BufferReader;
class BufferWriter;


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class SHA256 : public MessageDigest {

private:

	CryptoPP::SHA256 sha256_;

	static BC digestSize_;
	static BC blockSize_;


public:

	SHA256();

	virtual const BC&	getDigestSize() const;
	virtual const BC&	getBlockSize() const;

	virtual void 	reset();
	virtual void	update(const BufferReader& message);
	virtual void	finish(BufferWriter& hash);

	virtual ~SHA256();

};

#endif
