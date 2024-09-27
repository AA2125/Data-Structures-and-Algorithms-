#include <stdio.h>

const int BUFFER = 100;
// Buffer could be less but im lazy so i made a random guess.
// hint to myself pointers, lots of them 
// need to run 2 parallel pointers for the last task one for file and one for quote
// this is task 2 and 3 

void replaceCommaWithNewLine(char* line, int len) {
    int quoteMode = 0;
    for (char* i = line; i < (line+len) && *i != '\0'; i++) {
        if (*i == '\"') {
            quoteMode = 1 - quoteMode;
        } 
        else if (*i == ',' && quoteMode == 0) {
            *i = '\n';
        }
    }
}

void removeQuotes(char* line, int len) {
    char* linePtr = line;
    char* endPtr = line;

    while (*endPtr) {
        if (*endPtr == '\"') {
            *endPtr++;
        } else {
            *linePtr = *endPtr;
            *endPtr++; *linePtr++;
        }
    }
    *linePtr = 0;
}

int main (FILE*argv[1]) {
    FILE *fptr = fopen("Student.csv", "r");
    char line[BUFFER];
    while (fgets(line, BUFFER, fptr)) {
        replaceCommaWithNewLine(line, BUFFER);
        removeQuotes(line, BUFFER);

        printf("%s\n", line);
    }
}