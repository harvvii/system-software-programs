/*
This file contains code/program for "Reading content from console/terminal and writing that content in a new file."
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char sentence[1000];

    // file's pointer
    FILE *fptr;

    // writing mode for file
    fptr = fopen("program.txt", "w");

    // exiting program my new file
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    fprintf(fptr, "%s", sentence);
    fclose(fptr);
    return 0;
}
