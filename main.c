#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"



int main() {
    char text[256];
    const char* filename = "testcases.txt";

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    addtotextfile(filename, text);
    printf("Processed and added to file if not duplicate.\n");

    return 0;
}