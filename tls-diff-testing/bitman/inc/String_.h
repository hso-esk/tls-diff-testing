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

#ifndef __MyString_H__
#define __MyString_H__

#include <string>
#include <cstring>
#include <stdint.h>
#include <vector>
#include <cstdarg>


/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class String : public std::string {

public:

	static inline String getWhitespaces() {
		return String(" \t\r\n");
	}

	static inline String getNumerals() {
		return String("0123456789");
	}

	static inline String getLowerLetters() {
		return String("abcdefghijklmnopqrstuvwxyz");
	}

	static inline String getUpperLetters() {
		return String("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	}

	static inline String getLetters() {
		return getLowerLetters() + getUpperLetters();
	}

	static inline String getDefaultIDChars() {
		return getLetters() + getNumerals() + "_.";
	}


	static	String	format(const char* fmt, ...);
	static	String	hexDump(uint8_t* buf, size_t len,
						char* fmt = 0, char* space = 0);

	static	String	makeBoldWhite(const std::string& str);
	static	String	makeBoldPink(const std::string& str);
	static	String	makeBoldBlue(const std::string& str);
	static	String	makeBoldYellow(const std::string& str);
	static	String	makeBoldGreen(const std::string& str);
	static	String	makeBoldRed(const std::string& str);
	static	String	makePink(const std::string& str);
	static	String	makeBlue(const std::string& str);
	static	String	makeYellow(const std::string& str);
	static	String	makeGreen(const std::string& str);
	static	String	makeRed(const std::string& str);

	static	size_t	getCommonPrefixLength(const std::string& str1, const std::string& str2);
	static	size_t	getCommonPrefixLength(const std::vector<std::string>& strings);

	String();
	String(const String& str);
	String(const std::string& str);
	String(const char* str);

	String&	operator=(const String& str);
	String&	operator=(const std::string& str);
	String&	operator=(const char* str);

	String&	operator<<(const String& str);
	String&	operator<<(const std::string& str);
	String&	operator<<(const char* str);
	String&	operator<<(bool value);

	void	setWidth(size_t width, const char fill = ' ');
	String	getFixedWidth(size_t width, const char fill = ' ') const;
	size_t	getWidth() const;

	size_t	getNLines() const;

	size_t	cleanRemove(const char* str);
	size_t	cleanRemove(const std::string& str);
	size_t	cleanRemoveText(const char* str);
	size_t	cleanRemoveText(const std::string& str);
	size_t	cleanKeep(const char* str);
	size_t	cleanKeep(const std::string& str);

	void	prepend(const std::string& str);
	void	prepend(const char* str);

	void	appendRepeated(const String& str, size_t n);
	void	appendRepeated(const std::string& str, size_t n);
	void	appendRepeated(const char* str, size_t n);
	void	appendRepeated(const char str, size_t n);

	void	appendBool(bool value);
	void	appendBool(bool value, const std::string& strTrue, const std::string& strFalse);
	void	appendBool(bool value, const char* strTrue, const char* strFalse);

	void 	appendFixedWidth(const String& str, const size_t width, const char fill = ' ');
	void 	appendFixedWidth(const std::string& str, const size_t width, const char fill = ' ');
	void 	appendFixedWidth(const char* str, const size_t width, const char fill = ' ');

	void 	appendBoldWhite(const std::string& str);
	void 	appendBoldPink(const std::string& str);
	void 	appendBoldBlue(const std::string& str);
	void 	appendBoldYellow(const std::string& str);
	void 	appendBoldGreen(const std::string& str);
	void 	appendBoldRed(const std::string& str);
	void 	appendPink(const std::string& str);
	void 	appendBlue(const std::string& str);
	void 	appendYellow(const std::string& str);
	void 	appendGreen(const std::string& str);
	void 	appendRed(const std::string& str);

	void	assignHexDump(uint8_t* buf, size_t len,
				char* fmt = 0, char* space = 0);
	void	appendHexDump(uint8_t* buf, size_t len,
				char* fmt = 0, char* space = 0);
	void	prependHexDump(uint8_t* buf, size_t len,
				char* fmt = 0, char* space = 0);

	void	assignFormat(const char* fmt, va_list args);
	void	assignFormat(const char* fmt, ...);
	void	appendFormat(const char* fmt, ...);
	void	prependFormat(const char* fmt, ...);

	bool	beginsWith(const char* str) const;
	bool	beginsWith(const std::string& str) const;

	bool	endsWith(const char* str) const;
	bool	endsWith(const std::string& str) const;

	bool	contains(const char* str) const;
	bool	contains(const std::string& str) const;
	bool	containsOnly(const char* str) const;
	bool	containsOnly(const std::string& str) const;

	size_t	count(const char* str) const;
	size_t	count(const std::string& str) const;
	size_t	countLeading(const char* str) const;
	size_t	countLeading(const std::string& str) const;
	size_t	countLeadingUpTo(const char* str) const;
	size_t	countLeadingUpTo(const std::string& str) const;

	size_t	removeLeadingWhitespaces(const size_t nMax = 0);
	size_t	removeLeading(size_t n);
	size_t	removeLeading(const char* str, size_t nMax = 0);
	size_t	removeLeading(const std::string& str, size_t nMax = 0);
	bool	removeLeadingText(const char* str);
	bool	removeLeadingText(const std::string& str);

	bool	removeTrailingText(const char* str);
	bool	removeTrailingText(const std::string& str);

	size_t	countLines() const;

	size_t	getMaxLineWidth() const;

	size_t	indentLines(const std::string& indent, int fromLine = -1, int toLine = -1);

	void	appendColumn(const std::string& column, int width = -1);

	String	readLeading(const char* str, size_t nMax = 0);
	String	readLeading(const std::string& str, size_t nMax = 0);
	String	readLeadingUpTo(const char* str);
	String	readLeadingUpTo(const std::string& str);

	String	readLeadingBlock(const std::string& blocks = "[](){}", const std::string& quotes = "");

	String	readLeadingToken(const std::string& separator);

	String	getLeadingToken(const std::string& separator) const;
	String	getLeadingToken(const std::string& separator, bool& isLast) const;

	size_t	removeLeadingToken(const std::string& separator);

	size_t	findMatching(const std::string& blocks = "[](){}", const std::string& quotes = "", size_t pos = 0) const;

/*
	void	setBoldWhite();
	void	setBoldPink();
	void	setBoldBlue();
	void	setBoldYellow();
	void	setBoldGreen();
	void	setBoldRed();
	void	setPink();
	void	setBlue();
	void	setYellow();
	void	setGreen();
	void	setRed();
*/
};

#endif
