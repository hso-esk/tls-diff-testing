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

#include <DataUnitStream.h>
#include "StreamReader.h"
#include "DataUnit.h"
#include "DataUnitFragment.h"

using std::vector;


/*
 * ___________________________________________________________________________
 */
TypeDescriptor DataUnitStream::desc_(
		StreamVectorDataUnit::typeDescriptor(), 0, "DataUnitStream");


/*
 * ___________________________________________________________________________
 */
DataUnitStream::DataUnitStream(DataUnit* unit) {

	this->setElementTemplate(unit);
}


/*
 * ___________________________________________________________________________
 */
const TypeDescriptor& DataUnitStream::getTypeDescriptor() const {

	return typeDescriptor();
}


/*
 * ___________________________________________________________________________
 */
DataUnitFragment* DataUnitStream::newFragment(const BC& size) {

	DataUnitFragment* sdu = new DataUnitFragment(*this, size);
	fragments_.push_back(sdu);
	return sdu;
}


/*
 * ___________________________________________________________________________
 */
DataUnitStream::~DataUnitStream() {

	while (fragments_.size() > 0) {
		delete fragments_.back();
		fragments_.pop_back();
	}
}

