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

#include "String_.h"
#include <cstdlib>
#include <cstdio>
#include <iostream> // TODO: remove!

using std::string;
using std::vector;


/*
 * ___________________________________________________________________________
 */
String String::format(const char* fmt, ...) {

	va_list args;
	va_start(args, fmt);

	String str;
	str.assignFormat(fmt, args);

	va_end(args);

	return str;
}


/*
 * ___________________________________________________________________________
 */
String String::hexDump(uint8_t* buf, size_t len, char* fmt, char* space) {

	String str;
	str.assignHexDump(buf, len, fmt, space);
	return str;
}


/*
 * ___________________________________________________________________________
 */
size_t String::getCommonPrefixLength(
		const string& str1, const string& str2) {

	size_t len = 0;
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	while (len < len1 && len < len2 && str1[len] == str2[len]) {
		len++;
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
size_t String::getCommonPrefixLength(const vector<string>& strings) {

	size_t len = 0;

	size_t n = strings.size();
	for (size_t i = 0; i < n && (len > 0 || i == 0); i++) {
		if (i == 0) {
			len = strings[i].length();
		} else {
			size_t subLen = getCommonPrefixLength(strings[0], strings[i]);
			if (subLen < len) {
				len = subLen;
			}
		}
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
String::String() : string() {
}


/*
 * ___________________________________________________________________________
 */
String::String(const String& str) : string(str) {
}


/*
 * ___________________________________________________________________________
 */
String::String(const string& str) : string(str) {
}


/*
 * ___________________________________________________________________________
 */
String::String(const char* str) : string(str) {
}


/*
 * ___________________________________________________________________________
 */
String& String::operator=(const String& str) {

	this->assign(str);
	return *this;
}


/*
 * ___________________________________________________________________________
 */
String& String::operator=(const string& str) {

	this->assign(str);
	return *this;
}


/*
 * ___________________________________________________________________________
 */
String& String::operator=(const char* str) {

	this->assign(str);
	return *this;
}


/*
 * ___________________________________________________________________________
 */
String& String::operator<<(const String& str) {

	this->append(str);
	return *this;
}


/*
 * ___________________________________________________________________________
 */
String& String::operator<<(const string& str) {

	this->append(str);
	return *this;
}


/*
 * ___________________________________________________________________________
 */
String& String::operator<<(const char* str) {

	this->append(str);
	return *this;
}


/*
 * ___________________________________________________________________________
 */
String& String::operator<<(bool value) {

	this->appendBool(value);
	return *this;
}


/*
 * ___________________________________________________________________________
 */
String String::getFixedWidth(size_t width, const char fill) const {

	String str(*this);
	str.setWidth(width, fill);
	return str;
}


/*
 * ___________________________________________________________________________
 */
void String::setWidth(size_t width, const char fill) {

	/* this string's length */
	size_t len = this->length();

	/* true during scanning ANSI sequence */
	bool inSeq = false;

	/* scan string */
	size_t i;
	for (i = 0; i < len && width > 0; i++) {
		if (!inSeq) {
			if (this->at(i) == '\033') {
				inSeq = true;
			} else if (width > 0) {
				width--;
			}
		} else if (this->at(i) == 'm') {
			inSeq = false;
		}
	}

	if (width == 0) {
		/* now append all ANSI control sequences that have been missed */
		size_t start = i;
		for (; i < len; i++) {
			if (!inSeq) {
				if (this->at(i) == '\033' || i == len - 1) {
					inSeq = true;
					if (i == len - 1) {
						i++;
					}
					this->erase(start, i - start);
					len -= i - start;
					i = start;
				}
			} else if (this->at(i) == 'm') {
				inSeq = false;
				start = i + 1;
			}
		}
	} else {
		/* append fill characters to increase length of string */
		this->append(width, fill);
	}
}


/*
 * ___________________________________________________________________________
 */
size_t String::getWidth() const {

	/* this string's length */
	size_t len = this->length();

	/* true during scanning ANSI sequence */
	bool inSeq = false;

	/* scan string */
	size_t width = 0;
	size_t i;
	for (i = 0; i < len; i++) {
		if (!inSeq) {
			if (this->at(i) == '\033') {
				inSeq = true;
			} else {
				width++;
			}
		} else if (this->at(i) == 'm') {
			inSeq = false;
		}
	}

	return width;
}


/*
 * ___________________________________________________________________________
 */
size_t String::getNLines() const {

	size_t nLines = 0;

	size_t pos = 0;
	size_t len = this->length();
	while (pos < len && pos != string::npos) {
		pos = this->find_first_of('\n', pos);
		if (pos != string::npos) {
			++nLines;
			++pos;
		}
	}
	if (len > 0) {
		++nLines;
	}

	return nLines;
}


/*
 * ___________________________________________________________________________
 */
size_t String::cleanKeep(const char* str) {

	return this->cleanKeep(string(str));
}


/*
 * ___________________________________________________________________________
 */
size_t String::cleanKeep(const string& str) {

	size_t cnt = 0;
	for (size_t i = 0; i < this->length();) {
		if (str.find((*this)[i]) != string::npos) {
			/* keep character */
			i++;
		} else {
			/* remove character */
			this->erase(i, 1);
			cnt++;
		}
	}
	return cnt;
}


/*
 * ___________________________________________________________________________
 */
size_t String::cleanRemove(const char* str) {

	return this->cleanRemove(string(str));
}


/*
 * ___________________________________________________________________________
 */
size_t String::cleanRemove(const string& str) {

	size_t cnt = 0;
	for (size_t i = 0; i < this->length();) {
		if (str.find((*this)[i]) != string::npos) {
			/* remove character */
			this->erase(i, 1);
			cnt++;
		} else {
			/* keep character */
			i++;
		}
	}
	return cnt;
}


/*
 * ___________________________________________________________________________
 */
size_t String::cleanRemoveText(const char* str) {

	return this->cleanRemoveText(string(str));
}


/*
 * ___________________________________________________________________________
 */
size_t String::cleanRemoveText(const string& str) {

	size_t cnt = 0;
	size_t pos = 0;
	do {
		pos = this->find(str, pos);
		if (pos != string::npos) {
			this->erase(pos, str.length());
			cnt++;
		}
	} while (pos != string::npos && pos < this->length());

	return cnt;
}


/*
 * ___________________________________________________________________________
 */
void String::prepend(const char* str) {

	String appendix = *this;
	this->assign(str);
	this->append(appendix);
}


/*
 * ___________________________________________________________________________
 */
void String::prepend(const string& str) {

	String appendix = *this;
	this->assign(str);
	this->append(appendix);
}


/*
 * ___________________________________________________________________________
 */
void String::appendRepeated(const char str, size_t n) {

	this->append(n, str);
}


/*
 * ___________________________________________________________________________
 */
void String::appendRepeated(const char* str, size_t n) {

	for (size_t i = 0; i < n; i++) {
		this->append(str);
	}
}


/*
 * ___________________________________________________________________________
 */
void String::appendRepeated(const string& str, size_t n) {

	for (size_t i = 0; i < n; i++) {
		this->append(str);
	}
}


/*
 * ___________________________________________________________________________
 */
void String::appendRepeated(const String& str, size_t n) {

	for (size_t i = 0; i < n; i++) {
		this->append(str);
	}
}


/*
 * ___________________________________________________________________________
 */
void String::appendBool(bool value) {

	this->appendBool(value, "true", "false");
}


/*
 * ___________________________________________________________________________
 */
void String::appendBool(bool value, const string& strTrue, const string& strFalse) {

	if (value) {
		this->append(strTrue);
	} else {
		this->append(strFalse);
	}
}


/*
 * ___________________________________________________________________________
 */
void String::appendBool(bool value, const char* strTrue, const char* strFalse) {

	this->appendBool(value, string(strTrue), string(strFalse));
}


/*
 * ___________________________________________________________________________
 */
void String::appendFixedWidth(const String& str, const size_t width, const char fill) {

	String appendix(str);
	appendix.setWidth(width, fill);
	this->append(appendix);
}


/*
 * ___________________________________________________________________________
 */
void String::appendFixedWidth(const string& str, const size_t width, const char fill) {

	String appendix(str);
	appendix.setWidth(width, fill);
	this->append(appendix);
}


/*
 * ___________________________________________________________________________
 */
void String::appendFixedWidth(const char* str, const size_t width, const char fill) {

	String appendix(str);
	appendix.setWidth(width, fill);
	this->append(appendix);
}


/*
 * ___________________________________________________________________________
 */
void String::assignHexDump(uint8_t* buf, size_t len, char* fmt, char* space) {

	if (fmt == 0) {
		fmt = (char*)"%.2X";
	}
	if (space == 0) {
		space = (char*)" ";
	}

	this->clear();

	if (buf != 0) {
		for (size_t i = 0; i < len; i++) {
			this->appendFormat(fmt, buf[i]);
			if (i + 1 < len) {
				this->append(space);
			}
		}
	}
}


/*
 * ___________________________________________________________________________
 */
void String::appendHexDump(uint8_t* buf, size_t len, char* fmt, char* space) {

	String str;
	str.assignHexDump(buf, len, fmt, space);
	this->append(str);
}


/*
 * ___________________________________________________________________________
 */
void String::prependHexDump(uint8_t* buf, size_t len, char* fmt, char* space) {

	String str;
	str.assignHexDump(buf, len, fmt, space);
	this->prepend(str);
}


/*
 * ___________________________________________________________________________
 */
void String::assignFormat(const char* fmt, va_list args) {

	ssize_t	len = strlen(fmt);
	char*	buf = (char*)0;
	ssize_t	n = 0;

	do {
		va_list args2;
		va_copy(args2, args);

		buf = (char*)malloc(len);
		if (buf != 0) {
			/* format the string */
			n = vsnprintf(buf, len, fmt, args2);
			if (n == -1 || n >= len) {
				/* determine size for reallocation of string buffer */
				if (n == -1) { //TODO: correct?
					len *= 2;
				} else {
					len = n + 1;
				}
				free(buf);
			} else {
				/* we are done...string formatting succeeded */
				len = 0;
			}
		}

		va_end(args2);
	} while (buf != 0 && len > 0);

	if (buf != 0) {
		this->assign(buf);
		free(buf);
	}
}


/*
 * ___________________________________________________________________________
 */
void String::assignFormat(const char* fmt, ...) {

	va_list args;
	va_start(args, fmt);

	this->assignFormat(fmt, args);

	va_end(args);
}


/*
 * ___________________________________________________________________________
 */
void String::appendFormat(const char* fmt, ...) {

	va_list args;
	va_start(args, fmt);

	String str;
	str.assignFormat(fmt, args);
	this->append(str);

	va_end(args);
}


/*
 * ___________________________________________________________________________
 */
void String::prependFormat(const char* fmt, ...) {

	va_list args;
	va_start(args, fmt);

	String str;
	str.assignFormat(fmt, args);
	this->prepend(str);

	va_end(args);
}


/*
 * ___________________________________________________________________________
 */
bool String::beginsWith(const char* str) const {

	return (this->find(str) == 0);
}


/*
 * ___________________________________________________________________________
 */
bool String::beginsWith(const string& str) const {

	return (this->find(str) == 0);
}


/*
 * ___________________________________________________________________________
 */
bool String::endsWith(const char* str) const {

	return (this->find(str) == (this->length() - strlen(str)));
}


/*
 * ___________________________________________________________________________
 */
bool String::endsWith(const string& str) const {

	return (this->find(str) == (this->length() - str.length()));
}


/*
 * ___________________________________________________________________________
 */
bool String::contains(const char* str) const {

	return (this->find(str) != string::npos);
}


/*
 * ___________________________________________________________________________
 */
bool String::contains(const string& str) const {

	return (this->find(str) != string::npos);
}


/*
 * ___________________________________________________________________________
 */
bool String::containsOnly(const char* str) const {

	return (this->count(str) == this->length());
}


/*
 * ___________________________________________________________________________
 */
bool String::containsOnly(const string& str) const {

	return (this->count(str) == this->length());
}


/*
 * ___________________________________________________________________________
 */
size_t String::count(const char* str) const {

	return this->count(string(str));
}


/*
 * ___________________________________________________________________________
 */
size_t String::count(const string& str) const {

	size_t n = this->length();
	size_t cnt = 0;
	for (size_t i = 0; i < n; i++) {
		if (str.find((*this)[i]) != string::npos) {
			cnt++;
		}
	}
	return cnt;
}


/*
 * ___________________________________________________________________________
 */
size_t String::countLeading(const char* str) const {

	return this->countLeading(string(str));
}


/*
 * ___________________________________________________________________________
 */
size_t String::countLeading(const string& str) const {

	size_t cnt = 0;
	while (cnt < this->length() && str.find((*this)[cnt]) != string::npos) {
		cnt++;
	}
	return cnt;
}


/*
 * ___________________________________________________________________________
 */
size_t String::countLeadingUpTo(const char* str) const {

	return this->countLeadingUpTo(string(str));
}


/*
 * ___________________________________________________________________________
 */
size_t String::countLeadingUpTo(const string& str) const {

	size_t cnt = 0;
	while (cnt < this->length() && str.find((*this)[cnt]) == string::npos) {
		cnt++;
	}
	return cnt;
}


/*
 * ___________________________________________________________________________
 */
size_t String::removeLeading(size_t n) {

	if (n > this->length()) {
		n = this->length();
	}
	this->erase(0, n);
	return n;
}


/*
 * ___________________________________________________________________________
 */
size_t String::removeLeading(const char* str, size_t nMax) {

	size_t cnt = this->countLeading(str);
	if (nMax > 0 && cnt > nMax) {
		cnt = nMax;
	}
	this->erase(0, cnt);
	return cnt;
}


/*
 * ___________________________________________________________________________
 */
size_t String::removeLeading(const string& str, size_t nMax) {

	size_t cnt = this->countLeading(str);
	if (nMax > 0 && cnt > nMax) {
		cnt = nMax;
	}
	this->erase(0, cnt);
	return cnt;
}


/*
 * ___________________________________________________________________________
 */
size_t String::removeLeadingWhitespaces(const size_t nMax) {

	return this->removeLeading(String::getWhitespaces(), nMax);
}


/*
 * ___________________________________________________________________________
 */
bool String::removeLeadingText(const char* str) {

	bool begins = this->beginsWith(str);
	if (begins) {
		this->erase(0, strlen(str));
	}
	return begins;
}


/*
 * ___________________________________________________________________________
 */
bool String::removeLeadingText(const string& str) {

	bool begins = this->beginsWith(str);
	if (begins) {
		this->erase(0, str.length());
	}
	return begins;
}


/*
 * ___________________________________________________________________________
 */
bool String::removeTrailingText(const char* str) {

	bool ends = this->endsWith(str);
	if (ends) {
		size_t len = strlen(str);
		this->erase(this->length() - len, len);
	}
	return ends;
}


/*
 * ___________________________________________________________________________
 */
bool String::removeTrailingText(const string& str) {

	bool ends = this->endsWith(str);
	if (ends) {
		size_t len = str.length();
		this->erase(this->length() - len, len);
	}
	return ends;
}


/*
 * ___________________________________________________________________________
 */
size_t String::countLines() const {

	size_t n = 0;
	size_t pos = 0;
	size_t len = this->length();

	while (pos < len && pos != string::npos) {
		n++;
		pos = this->find_first_of('\n', pos);
		if (pos != string::npos) {
			++pos;
		}
	}

	return n;
}


/*
 * ___________________________________________________________________________
 */
size_t String::getMaxLineWidth() const {

	return 0;
}


/*
 * ___________________________________________________________________________
 */
size_t String::indentLines(const std::string& indent,
		int fromLine, int toLine) {

	size_t len = this->length();
	size_t iLine = 0;
	size_t pos = 0;
	size_t n = 0;

	while (pos < len && (toLine < 0 || iLine <= (size_t)toLine)) {
		if (fromLine < 0 || iLine >= (size_t)fromLine) {
			/* insert indentation string */
			this->insert(pos, indent);
			len += indent.length();
			++n;
		}
		/* find the next new line */
		pos = this->find_first_of("\n", pos);
		if (pos != string::npos) {
			++pos;
			/* we have reached a new line in the string */
			++iLine;
			if (pos < len && (*this)[pos] == '\r') {
				/* proceed past potential \r characters */
				++pos;
			}
		}
	}

	return n;
}


/*
 * ___________________________________________________________________________
 */
void String::appendColumn(const std::string& column, int width) {

	size_t pos1 = 0;
	size_t pos2 = 0;
	size_t len1 = this->length();
	size_t len2 = column.length();

	size_t insertAt;
	size_t insertFrom = 0;
	size_t insertLen;

	String line;

	while (pos1 <= len1) {

		/* set pos1 to the end of the current line
		 * right before \r and/or \n characters */
		insertAt = this->find_first_of('\n', pos1);
		if (insertAt == string::npos) {
			insertAt = len1;
		}
		pos1 = insertAt + 1;
		if (insertAt > 0 && (*this)[insertAt - 1] == '\r') {
			--insertAt;
		}

		if (pos2 < len2) {
			/* determine portion of string to add as next line */
			insertFrom = pos2;
			insertLen = column.find_first_of('\n', pos2);
			if (insertLen == string::npos) {
				insertLen = len2;
			}
			pos2 = insertLen + 1;
			if (insertLen > 0 && column[insertLen - 1] == '\r') {
				--insertLen;
			}
			insertLen -= insertFrom;

			line = column.substr(insertFrom, insertLen);
		} else {
			line.clear();
		}

		if (width >= 0) {
			line.setWidth(width);
		}

		this->insert(insertAt, line);
		len1 += line.length();
		pos1 += line.length();
	}
}


/*
 * ___________________________________________________________________________
 */
String String::readLeading(const char* str, size_t nMax) {

	return this->readLeading(string(str), nMax);
}


/*
 * ___________________________________________________________________________
 */
String String::readLeading(const string& str, size_t nMax) {

	String token;
	size_t len = this->countLeading(str);
	if (nMax > 0 && len > nMax) {
		len = nMax;
	}
	if (len > 0) {
		token = this->substr(0, len);
		this->erase(0, len);
	}
	return token;
}


/*
 * ___________________________________________________________________________
 */
String String::readLeadingUpTo(const char* str) {

	return this->readLeadingUpTo(string(str));
}


/*
 * ___________________________________________________________________________
 */
String String::readLeadingUpTo(const string& str) {

	String token;
	size_t len = this->countLeadingUpTo(str);
	if (len > 0) {
		token = this->substr(0, len);
		this->erase(0, len);
	}
	return token;
}


/*
 * ___________________________________________________________________________
 */
String String::readLeadingBlock(const string& blocks, const string& quotes) {

	String result;

	size_t match = this->findMatching(blocks, quotes);
	if (match != string::npos) {
		result = this->substr(1, match - 1);
		this->erase(0, match + 1);
	}

	return result;
}


/*
 * ___________________________________________________________________________
 */
String String::getLeadingToken(const string& separator) const {

	bool dummy = false;
	return this->getLeadingToken(separator, dummy);
}


/*
 * ___________________________________________________________________________
 */
String String::getLeadingToken(const string& separator, bool& isLast) const {

	String token;

	size_t pos = this->find(separator);
	if (pos != string::npos) {
		token = this->substr(0, pos);
		isLast = false;
	} else {
		token = *this;
		isLast = true;
	}

	return token;
}


/*
 * ___________________________________________________________________________
 */
String String::readLeadingToken(const string& separator) {

	bool isLast = false;
	String token = this->getLeadingToken(separator, isLast);

	if (!isLast) {
		this->erase(0, token.length() + separator.length());
	} else {
		this->clear();
	}

	return token;
}


/*
 * ___________________________________________________________________________
 */
size_t String::removeLeadingToken(const string& separator) {

	bool isLast = false;
	String token = this->getLeadingToken(separator, isLast);

	size_t len = 0;
	if (!isLast) {
		len = token.length() + separator.length();
		this->erase(0, len);
	} else {
		len = this->length();
		this->clear();
	}

	return len;
}


/*
 * ___________________________________________________________________________
 */
size_t String::findMatching(const string& blocks, const string& quotes, size_t pos) const {

	if ((blocks.length() % 2) != 0) {
		return string::npos;
	}

	size_t index = blocks.find((*this)[pos++]);
	if (index == string::npos) {
		return string::npos;
	} else {
		index++;
	}

	//std::cout << "Looking for " << blocks[index] << " @ " << index << std::endl;

	bool found = false;
	while (!found && pos < this->length() && pos != string::npos) {

		size_t blockPos = this->find_first_of(blocks, pos);

		if (blockPos != string::npos) {

			size_t blockType = blocks.find((*this)[blockPos]);
			if (blockType == index) {

				pos = blockPos;
				found = true;

			} else if (blockType % 2 == 0) {

				pos = this->findMatching(blocks, quotes, blockPos);
				if (pos != string::npos) {
					pos++;
				}

			} else {
				/* we found an unexpected closing block */
				pos = string::npos;
			}

		} else {
			pos = string::npos;
		}
	}

	return pos;
}


/*
 * ============================================================================
 */

void String::appendBoldWhite(const string& str) {

	this->append(String::makeBoldWhite(str));
}

void String::appendBoldPink(const string& str) {

	this->append(String::makeBoldPink(str));
}

void String::appendBoldBlue(const string& str) {

	this->append(String::makeBoldBlue(str));
}

void String::appendBoldYellow(const string& str) {

	this->append(String::makeBoldYellow(str));
}

void String::appendBoldGreen(const string& str) {

	this->append(String::makeBoldGreen(str));
}

void String::appendBoldRed(const string& str) {

	this->append(String::makeBoldRed(str));
}

void String::appendPink(const string& str) {

	this->append(String::makePink(str));
}

void String::appendBlue(const string& str) {

	this->append(String::makeBlue(str));
}

void String::appendYellow(const string& str) {

	this->append(String::makeYellow(str));
}

void String::appendGreen(const string& str) {

	this->append(String::makeGreen(str));
}

void String::appendRed(const string& str) {

	this->append(String::makeRed(str));
}


/*
 * ============================================================================
 */

String String::makeBoldWhite(const string& str) {

	String ret(str);
	ret.prepend("\033[1m");
	ret.append("\033[0m");
	return ret;
}

String String::makeBoldPink(const string& str) {

	String ret(str);
	ret.prepend("\033[1;35m");
	ret.append("\033[0m");
	return ret;
}

String String::makeBoldBlue(const string& str) {

	String ret(str);
	ret.prepend("\033[1;34m");
	ret.append("\033[0m");
	return ret;
}

String String::makeBoldYellow(const string& str) {

	String ret(str);
	ret.prepend("\033[1;33m");
	ret.append("\033[0m");
	return ret;
}

String String::makeBoldGreen(const string& str) {

	String ret(str);
	ret.prepend("\033[1;32m");
	ret.append("\033[0m");
	return ret;
}

String String::makeBoldRed(const string& str) {

	String ret(str);
	ret.prepend("\033[1;31m");
	ret.append("\033[0m");
	return ret;
}

String String::makePink(const string& str) {

	String ret(str);
	ret.prepend("\033[35m");
	ret.append("\033[0m");
	return ret;
}

String String::makeBlue(const string& str) {

	String ret(str);
	ret.prepend("\033[34m");
	ret.append("\033[0m");
	return ret;
}

String String::makeYellow(const string& str) {

	String ret(str);
	ret.prepend("\033[33m");
	ret.append("\033[0m");
	return ret;
}

String String::makeGreen(const string& str) {

	String ret(str);
	ret.prepend("\033[32m");
	ret.append("\033[0m");
	return ret;
}

String String::makeRed(const string& str) {

	String ret(str);
	ret.prepend("\033[31m");
	ret.append("\033[0m");
	return ret;
}

