#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"



int main() {
    char text[256];
    const char* filename = "testcases.txt";

    printf("Enter a string: \n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;
    if(strlen(text) == 0) {
        printf("Empty string provided.\n");
        return 1;
    }
    if(strlen(text) > 255) {
        printf("String too long. Maximum length is 255 characters.\n");
        return 1;
    }
    int nb = lengthOfLongestSubstring(text);
    if((isinfile(filename, text))) {
        printf("String already exists in file.\n");

        printf("Length of longest substring without repeating characters: %d\n", nb);
        return 1;
    }else{
        printf("String does not exist in file. Proceeding to add.\n");
        addtotextfile(filename, text);
        
        printf("Length of longest substring without repeating characters: %d\n", nb);
        printf("Processed and added to file if not duplicate.\n");
    }
    

    
    
    


    return 0;
}