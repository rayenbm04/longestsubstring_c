#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




int lengthOfLongestSubstring(char *s) {
    int freq[256] = {0};
    int left = 0, maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        freq[(unsigned char)s[right]]++;
        while (freq[(unsigned char)s[right]] > 1) {
            freq[(unsigned char)s[left]]--;
            left++;
        }

        int windowLen = right - left + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;
    }

    return maxLen;
}

bool isinfile(const char* filename, const char* text) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }
    char buffer[1024];
    bool found = false;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, text) != NULL) {
            found = true;
            break;
        }
    }
    fclose(file);
    return found;
}

void addtotextfile(const char* filename, const char* text) {
    
    int nb =lengthOfLongestSubstring((char*)text);
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        return;
    }
    fprintf(file, "%s   %d\n", text, nb);
    
    fclose(file);
    return;

}