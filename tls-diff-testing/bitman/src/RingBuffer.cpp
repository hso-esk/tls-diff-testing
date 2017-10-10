#include <cstdlib>
#include <cstdio>

#include "BC.h"
#include "RingBuffer.h"


/*
 * ___________________________________________________________________________
 */
RingBuffer::RingBuffer() : capacity_(-1) {
}


/*
 * ___________________________________________________________________________
 */
RingBuffer::RingBuffer(const BC& capacity) : capacity_(capacity) {
}


/*
 * ___________________________________________________________________________
 */
void RingBuffer::clear() {

	this->clear_();
}


/*
 * ___________________________________________________________________________
 */
BC RingBuffer::getCapacity() const {

	return capacity_;
}


/*
 * ___________________________________________________________________________
 */
BC RingBuffer::getRemainingCapacity() const {

	BC remCap = capacity_;

	if (remCap.isDef()) {
		BC len = this->getLength();
		if (remCap >= len) {
			remCap -= len;
		} else {
			remCap = 0;
		}
	}

	return remCap;
}


/*
 * ___________________________________________________________________________
 */
RingBuffer::~RingBuffer() {
}
