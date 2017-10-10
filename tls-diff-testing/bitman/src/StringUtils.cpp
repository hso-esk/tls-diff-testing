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

#include "StringUtils.h"

using std::string;
using std::vector;


/*
 *
 */
string StringUtils::getHexCharacters() {

    return "0123456789abcdefABCDEF";
}


/*
 *
 */
int StringUtils::hexDigitToDec(char digit) {

    /* convert to lower cases */
    if (digit >= 'a' && digit <= 'z') {
        digit -= 'a' - 'A';
    }

    string base = "0123456789ABCDEF";

    size_t pos = base.find(digit);
    if (pos != string::npos) {
        return (int)pos;
    } else {
        return -1;
    }
}


/*
 *
 */
string StringUtils::filter(string input, string characters) {

    string output;

    for (size_t i = 0; i < input.length(); i++) {
        if (characters.find(input[i]) != string::npos) {
            output.append(input, i, 1);
        }
    }

    return output;
}


/*
 *
 */
string StringUtils::filterHex(string input) {

    size_t pos = 0;
    while (pos != string::npos) {
        pos = input.find("0x", pos, 2);
        if (pos != string::npos) {
            input[pos] = ' ';
        }
    }

    return StringUtils::filter(input, StringUtils::getHexCharacters());
}


/*
 *
 */
uint32_t StringUtils::hexToDec(string hex) {

    uint32_t retVal = 0;
    string input = filterHex(hex);

    for (size_t i = 0; i < input.length(); i++) {
        int val = hexDigitToDec(input[i]);
        if (val != -1) {
            retVal *= 16;
            retVal += val;
        }
    }

    return retVal;
}


/*
 *
 */
vector<uint8_t>* StringUtils::readHex(string input) {

    vector<uint8_t>* vec = 0;
    string filtered = filterHex(input);

    if (filtered.length() % 2 == 0) {
        vec = new vector<uint8_t>();
        for (size_t i = 0; i < filtered.length(); i += 2) {
            string digit = filtered.substr(i, 2);
            uint8_t val = (uint8_t)hexToDec(digit);
            vec->push_back(val);
        }
    }

    return vec;
}
