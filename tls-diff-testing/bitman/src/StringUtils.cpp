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
