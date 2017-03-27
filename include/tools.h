#include <stdio.h> /* FILE, vprintf, vsprintf */
#include <stdarg.h> /* va_list, va_start, va_end */
#include <ctype.h> /* tolower */

#ifndef TOOLS
#define TOOLS

/*
 * isvowel() determines whether the supplied character is a vowel.
 * note: function ignores whether supplied character is a lower
 * or upper case letter.
 */
int isvowel(char c);

/*
 * isduplicate() determines whether both characters are equal.
 * note: function ignores whether supplied characters are lower or upper
 * case letters.
 */
int isduplicate(char c0, char c1);

/*
 * wdprintf() prints to the file stream as well as stdout iff the supplied
 * stream is not a stdout.
 */
void wdprintf(FILE *stream, const char * format, ...);

#endif // TOOLS