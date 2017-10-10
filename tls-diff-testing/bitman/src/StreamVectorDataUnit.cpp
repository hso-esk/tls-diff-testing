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

#include "StreamVectorDataUnit.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor StreamVectorDataUnit::desc_(
		VectorDataUnit::typeDescriptor(), 0, "StreamVectorDataUnit");


/*
 * ___________________________________________________________________________
 */
StreamVectorDataUnit::StreamVectorDataUnit() :
		VectorDataUnit(false), N_(-1) {

}


/*
 * ___________________________________________________________________________
 */
StreamVectorDataUnit::StreamVectorDataUnit(const BC& N) :
		VectorDataUnit(N == 0), N_(N) {

	this->dissector().setSize(N_);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& StreamVectorDataUnit::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
bool StreamVectorDataUnit::expand_(
		size_t len, size_t decoded, bool dry, bool ahead) {

	bool ret = true;

	if (N_.isUndef() || this->dissector().getLength() < N_) {

		DataUnit* tail = this->getChildTail();
		if (!dry && (tail == 0 || !tail->dissector().isAccepting())) {
			/* create a new instance of the template data
			 * unit and attach it to the list of children */
			DataUnit* elementTemplate = this->getElementTemplate();
			if (elementTemplate != 0) {
				this->appendChild(elementTemplate->newInstance());
			}
		}

		/* this vector is not yet satisfied and expects to get more input */
		ret = false;
	}

	return ret;
}


/*
 * ___________________________________________________________________________
 */
DataUnit* StreamVectorDataUnit::newInstance_() const {

	StreamVectorDataUnit* vector = new StreamVectorDataUnit(N_);
	DataUnit* elementTemplate = this->getElementTemplate();
	if (elementTemplate != 0) {
		vector->setElementTemplate(elementTemplate->newInstance());
	}
	return vector;
}


/*
 * ___________________________________________________________________________
 */
StreamVectorDataUnit::~StreamVectorDataUnit() {
}

