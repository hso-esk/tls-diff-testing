/*
 *  Copyright (C) 2017
 *  Andreas Walz [andreas.walz@hs-offenburg.de]
 *  Offenburg University of Applied Sciences
 *  Institute of Reliable Embedded Systems and Communications Electronics (ivESK)
 *  [https://ivesk.hs-offenburg.de/]
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <iostream>
#include "Dissector.h"
#include "StreamReader.h"
#include "BufferReader.h"
#include "BufferStreamReader.h"
#include "DataUnit.h"

/* =========================================================================
 *
 * There is an important difference between 'dissector size' and 'dissector
 * length'. Size refers to the total amount of data that will be accepted
 * while length refers to the total amount of data that already has been
 * accepted.
 *
 * ========================================================================= */


/*
 * ___________________________________________________________________________
 */
Dissector::Dissector(DissectorBody& body) : body_(body), size_(-1),
		length_(0), overflow_(0), closed_(false), reader_(0) {
}


/*
 * ___________________________________________________________________________
 */
void Dissector::setSize(const BC& size) {

	if (size_.isUndef()) {
		size_ = size;
	} else {
		/* TODO: consider keeping the smaller size in this case?!? */
		throw std::runtime_error("Dissector::setDissectorSize(...): "
				"Attempt to redefine dissector size");
	}
}


/*
 * ___________________________________________________________________________
 */
bool Dissector::isAccepting() const {

	bool accepting = false;

	if (!closed_) {
		if (size_.isUndef()) {
			/* if the size has not been defined
			 * externally => let the body decide */
			accepting = body_.dissectorBodyIsAccepting();
		} else {
			/* if the size has been defined externally
			 * => let the acceptance decide */
			accepting = size_ > this->getLength();
		}
	}

	return accepting;
}


/*
 * ___________________________________________________________________________
 */
BC Dissector::reset() {

	/* reset the dissector body */
	body_.dissectorBodyReset();

	/* reset data counters*/
	length_ = 0;
	overflow_ = 0;

	/* open dissector */
	closed_ = false;

	/* return the dissector size */
	return size_;
}


/*
 * ___________________________________________________________________________
 */
BC Dissector::reset(const BC& size) {

	/* first set the dissector size */
	this->setSize(size);

	/* now reset the dissector */
	return this->reset();
}


/*
 * ___________________________________________________________________________
 */
BC Dissector::dissect(StreamReader& reader, const BC& max) {

	BC maxInput = BC::getMin(max, this->getAcceptance());
	StreamStreamReader subReader(reader, maxInput);

	BC len;
	reader_ = &subReader;
	len = body_.dissectorBodyDissect(subReader);
	reader_ = (StreamStreamReader*)0;

	if (len.isDef() && len != subReader.getAccumulator()) {
		/* this should never happen: the subReader lost more or less
		 * data than the dissectorBodyDissect(...) function returned */
		throw DissectionError("Dissector::dissect(...): "
				"Dissector returned invalid length");
	}

	length_ += len;

	if (!subReader.isEmpty()) {
		if (body_.dissectorBodyIsAccepting()) {
			/* this should never happen */
			throw DissectionError("Dissector::dissect(...): "
					"Dissector body rejected data");
		} else {
			BC acceptance = this->getAcceptance();
			if (acceptance.isDef() && acceptance > 0) {
				BC excess = subReader.flush(acceptance);
				length_ += excess;
				overflow_ += excess;
				len += excess;
			}
		}
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
BC Dissector::dissectFromBuffer(const BufferReader& reader, const BC& max) {

	BufferStreamReader subReader(reader);
	return this->dissect(subReader, max);
}


/*
 * ___________________________________________________________________________
 */
Dissector::~Dissector() {
}

