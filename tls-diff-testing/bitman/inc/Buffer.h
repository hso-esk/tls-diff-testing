#ifndef __Buffer_H__
#define __Buffer_H__

#include "BC.h"
#include "BufferReader.h"
#include "BufferWriter.h"
#include "BufferModifier.h"


class Buffer : public BufferReader, public BufferWriter, public BufferModifier {

private:

	/* TODO: Add description */
	BC	capacity_;


public:

	/* TODO: Add description */
	Buffer();

	/* TODO: Add description */
	Buffer(const BC& capacity);


	/* TODO: Add description */
	inline BC getCapacity() const {

		return capacity_;
	}

	/* TODO: Add description */
	BC getRemainingCapacity() const;


	/* TODO: Add description */
	virtual ~Buffer();

};

#endif
