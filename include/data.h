#include "../include/tools.h" /* wdprintf */
#include <stdio.h> /* FILE, printf */
#include <stdlib.h> /* malloc */
#include <ctype.h> /* ispunct, isspace, isalpha, isdigit, tolower */

#ifndef DATA
#define DATA

/*
 * struct Data stores the variables used during the program execution. These
 * are c - current character, cprev - previouse character, as well as vnum,
 * cnum, pnum, and dnum which store the number of occurences in line of each
 * letter type.
 */
typedef struct Data Data;

/*
 * resetData() sets the member variables of the struct Data to default
 * values, which are ascii NUL character for character type, and 0 for
 * the int type.
 */
void clearData(Data *cdata);

/*
 * makeData() allocates memory and initializes variables stored in struct
 * Data to default value using clearData() function.
 */
Data *makeData();

/*
 * takesNext() sets the current character stored in struct Data to the next
 * character read from a given input stream.
 */
int takesNext(FILE *stream, Data *cdata);

/*
 * hasLine() returns one iff the current character variable stored in struct
 * Data is set to the newline escape sequence.
 */
int hasLine(Data *cdata);

/*
 * printCharInfo() determines whether each character acquired from stream is
 * vowel, punctuation character, duplicate of previous character or numerical
 * value. On each successful identification increases the corresponding
 * counter of the type of a character that is stored in the struct Data and
 * prints each character along with its classification.
 */
void printCharInfo(FILE *stream, Data *cdata);

/*
 * printLineInfo() prints the information on amount of each character type
 * found in the supplied line.
 */
void printLineInfo(FILE* stream, Data *cdata);

/*
 * printLineStats() prints summary of the line in terms of average
 * amount of all vowels, consonants, punctuation marks and numbers
 * i.e., each character type found per line.
 */
void printLineStats(FILE *stream, Data *cdata);

#endif // DATA