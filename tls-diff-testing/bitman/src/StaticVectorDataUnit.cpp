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

#include "StaticVectorDataUnit.h"

using std::string;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor StaticVectorDataUnit::desc_(
		VectorDataUnit::typeDescriptor(), 0, "StaticVectorDataUnit");


/*
 * ___________________________________________________________________________
 */
StaticVectorDataUnit::StaticVectorDataUnit(size_t N) :
		VectorDataUnit(N == 0), N_(N) {

}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& StaticVectorDataUnit::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
bool StaticVectorDataUnit::expand_(
		size_t len, size_t decoded, bool dry, bool ahead) {

	DataUnit* elementTemplate = this->getElementTemplate();
	for (size_t i = len; i < N_; i++) {
		this->appendChild(elementTemplate->newInstance());
	}
	return true;
}


/*
 * ___________________________________________________________________________
 */
DataUnit* StaticVectorDataUnit::newInstance_() const {

	StaticVectorDataUnit* vector = new StaticVectorDataUnit(N_);
	DataUnit* elementTemplate = this->getElementTemplate();
	if (elementTemplate != 0) {
		vector->setElementTemplate(elementTemplate->newInstance());
	}
	return vector;
}


/*
 * ___________________________________________________________________________
 */
StaticVectorDataUnit::~StaticVectorDataUnit() {
}

