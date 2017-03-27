/*
* Assignemnt 2, Task 1, Version 4
*
* This program reads a line of text from either keyboard or file,
* and determines whether each character is a vowel, consonant, punctuation
* mark, duplicate of the previous character, or a number.
*
* After printing each character and its corresponding information, program
* outputs summary information in the form of amount of each character
* type in line and its average occurrence per line.
*
* Author: C. Stankiewicz
*
*/

#include <stdio.h> /* FILE, printf, fclose, fopen */
#include <stdlib.h> /* free, exit, EXIT_FAILURE,  EXIT_SUCCESS */
#include <string.h> /* strerror */
#include <errno.h> /* errno */
#include "../include/data.h"
#include "../include/tools.h"

int main(int argc, char **argv) {
    FILE *input = NULL, *output = NULL; // IO files
    Data *cdata = makeData();

    printf("a2t1, version 4.f\n"); // Program's info
    printf("\n");

    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (input == NULL) {
            wdprintf(stderr, "Unable to open '%s': %s\n",
                argv[1], strerror(errno));
            exit(EXIT_FAILURE);
        }
        output = fopen(argv[2], "w");
        if (output == NULL) {
            wdprintf(stderr, "Unable to open '%s': %s\n",
                argv[2], strerror(errno));
            exit(EXIT_FAILURE);
        }
    } // end of argc > 1
    else {
        input = stdin;
        output = stdout;
    } // end of IO stream acquisition

    while (takesNext(input, cdata)) { // while current char is not EOF
        printCharInfo(output, cdata);
        if (hasLine(cdata)) { // if current char is '\n'
            printLineInfo(output, cdata);
            printLineStats(output, cdata);
            clearData(cdata);
        }
    } // end of line evaluation

    fclose(output);
    fclose(input);
    free(cdata);

    return EXIT_SUCCESS;
}
