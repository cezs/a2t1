#include <stdio.h> /* FILE, printf */
#include <stdlib.h> /* malloc */
#include <ctype.h> /* ispunct, isspace, isalpha, isdigit, tolower */
#include "../include/tools.h" /* wdprintf */
#include "../include/data.h" /**/

struct Data {
    int c; // current character
    char cprev; // previous character
    int vnum, // number of the vowels
        cnum, // number of the consonants
        pnum, // number of the punctuation marks
        dnum; // number of the consecutive duplications of letters
};

void clearData(Data *cdata) {
    cdata->cprev = '\0'; // set to NUL character
    cdata->vnum = cdata->cnum = cdata->pnum = cdata->dnum = 0; // reset all counters 
} // end of clearData

Data *makeData() {
    Data *cdata = (Data*)malloc(sizeof(Data));
    if (cdata != NULL)
        clearData(cdata);
    return cdata;
} // end of makeData

int takesNext(FILE *stream, Data *cdata) {
    return ((cdata->c = fgetc(stream)) != EOF);
} // end of takesNext

int hasLine(Data *cdata) {
    if (cdata->c == '\n') {
        return 1;
    }
    else { 
        return 0;
    }
} // end of hasLine

void printCharInfo(FILE *stream, Data *cdata) {
    if (!isspace(cdata->c)) {
        wdprintf(stream, "%c -", cdata->c);
    }
    if (isalpha(cdata->c)) {
        if (isvowel(cdata->c)) {
            wdprintf(stream, " vowel");
            ++cdata->vnum;
        }
        else { // if (isalpha(cdata.c) && !isvowel(cdata.c))
            wdprintf(stream, " consonant");
            ++cdata->cnum;
        }
    }
    if (isduplicate(cdata->cprev, cdata->c)) {
        wdprintf(stream, " duplicate");
        ++cdata->dnum;
    }
    if (ispunct(cdata->c)) {
        wdprintf(stream, " punctuation mark");
        ++cdata->pnum;
    }
    if (isdigit(cdata->c)) {
        wdprintf(stream, " number");
    }

    wdprintf(stream, "\n");
    cdata->cprev = cdata->c;
} // end of printCharInfo

void printLineInfo(FILE* stream, Data *cdata) {
    char *ans = "vowels: %d\n"
        "consonants: %d\n"
        "punctuation marks: %d\n"
        "consecutive duplications: %d\n";
    int sum = cdata->vnum + cdata->cnum + cdata->pnum + cdata->dnum;

    if (sum != 0) { // && (c == '\n')
        wdprintf(stream,
            ans,
            cdata->vnum, cdata->cnum, cdata->pnum, cdata->dnum);
    }
    else {
        wdprintf(stream, "No line supplied.\n");
    }
    wdprintf(stream, "\n");
} // end of printLineInfo

void printLineStats(FILE *stream, Data *cdata) {
    double vavgpl, cavgpl, pmavgpl, davgpl;
    double sum = cdata->vnum + cdata->cnum + cdata->pnum;
    char* ans = "vowels avg per line: %f\n"
        "consonants avg per line: %f\n"
        "punctuation marks avg per line: %f\n"
        "consecutive duplications avg per line: %f\n";

    if (sum != 0)
    {
        vavgpl = (cdata->vnum / sum); // vowels avg per line
        cavgpl = (cdata->cnum / sum); // consonants avg per line 
        pmavgpl = (cdata->pnum / sum); // punctuation marks avg per line 
        davgpl = (cdata->dnum / sum); // consecutive duplications avg p.l

        wdprintf(stream, ans, vavgpl, cavgpl, pmavgpl, davgpl);
        wdprintf(stream, "\n");
    }
    else {
        wdprintf(stream, "No line supplied.\n");
    }
    wdprintf(stream, "\n");
} // end of printLineStats