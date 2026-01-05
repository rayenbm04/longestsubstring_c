
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "source.h"

void run_tests() {
    
    printf("Running Test 1: 'abcabcbb'...\n");
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    
    
    printf("Running Test 2: 'bbbbb'...\n");
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    
    
    printf("Running Test 3: Empty String...\n");
    assert(lengthOfLongestSubstring("") == 0);

    printf("Running Test 4: 'pwwkew'...\n");
    assert(lengthOfLongestSubstring("pwwkew") == 3);

    printf("ALL TESTS PASSED!\n");
}

int main() {
    run_tests();
    return 0;
}