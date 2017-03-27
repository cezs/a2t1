#include <stdio.h> /* FILE, vprintf, vsprintf */
#include <stdarg.h> /* va_list, va_start, va_end */
#include <ctype.h> /* tolower */
#include "../include/tools.h" /**/

int isvowel(char c) {
    int i;
    char *vowel = "aeiou"/*=={ 'a','e','i','o','u' }*/;

    for (i = 0; i < 5; ++i)
        if (tolower(c) == vowel[i]) // convert the character to lowercase before comparison
            return 1;
    return 0;
} // end of isvowel

int isduplicate(char c0, char c1) {
    if (tolower(c0) == tolower(c1)) // convert both characters to lowercase before comparison
        return 1;
    return 0;
} // end of isduplicate

void wdprintf(FILE *stream, const char * format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    if (stream != stdout)
        vfprintf(stream, format, args);
    va_end(args);
}