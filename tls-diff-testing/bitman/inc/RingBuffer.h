#ifndef __RingBuffer_H__
#define __RingBuffer_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cstdarg>
#include <stdint.h>
#include <vector>
#include "String_.h"
#include "StreamReader.h"
#include "BufferWriter.h"


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class RingBuffer : public StreamReader, public BufferWriter {

private:

	BC	capacity_;


protected:

	/* === To be implemented by sub-classes: =============================== */

	virtual void clear_() = 0;

	/* ===================================================================== */


public:

	RingBuffer();
	RingBuffer(const BC& capacity);

	void	clear();

	BC		getCapacity() const;
	BC		getRemainingCapacity() const;

	virtual ~RingBuffer();

};

#endif
