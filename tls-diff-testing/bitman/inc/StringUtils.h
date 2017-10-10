#ifndef __StringUtils_H__
#define __StringUtils_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <inttypes.h>


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class StringUtils {

public:

    static std::string getHexCharacters();

    static int hexDigitToDec(char digit);

    static std::string filter(std::string input, std::string characters);

    static std::string filterHex(std::string input);

    static uint32_t hexToDec(std::string hex);

    static std::vector<uint8_t>* readHex(std::string input);

};

#endif
