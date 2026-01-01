#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"



int main() {
    char text[256];
    const char* filename = "testcases.txt";

    printf("Enter a string(enter ** to stop): \n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;
    while(strcmp(text, "**") != 0) {
        if(strlen(text) == 0) {
            printf("Empty string provided.\n");
        } else if(strlen(text) > 255) {
            printf("String too long. Maximum length is 255 characters.\n");
        } else {
            int nb = lengthOfLongestSubstring(text);
            if(isinfile(filename, text)) {
                printf("String already exists in file.\n");
            } else {
                printf("String does not exist in file. Proceeding to add.\n");
                addtotextfile(filename, text);
                printf("Processed and added to file if not duplicate.\n");
            }
            printf("Length of longest substring without repeating characters: %d\n", nb);
        }
        printf("Enter a string(enter ** to stop): \n");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = 0;
    }
    printf("Program terminated.\n");
    return 0;
}