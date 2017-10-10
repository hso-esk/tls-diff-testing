#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>

#include "BC.h"
#include "Buffer.h"
#include "BufferStreamReader.h"


/*
 * ___________________________________________________________________________
 */
Buffer::Buffer() : capacity_(-1) {
}


/*
 * ___________________________________________________________________________
 */
Buffer::Buffer(const BC& capacity) : capacity_(capacity) {
}


/*
 * ___________________________________________________________________________
 */
BC Buffer::getRemainingCapacity() const {

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
Buffer::~Buffer() {
}
