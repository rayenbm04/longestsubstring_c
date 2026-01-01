# Longest Substring Without Repeating Characters

This project is a C-based command-line tool designed to calculate the length of the longest substring within a given string that contains no repeating characters. It includes a persistent storage system that saves unique test cases and their results to a file, preventing duplicate processing.

## Table of Contents
1. Project Overview
2. Methodology
3. Challenges and Implementation Details
4. Function Documentation
5. Installation and Execution

## 1. Project Overview
The program provides an interactive shell where users can input strings for analysis. The system calculates the length of the longest unique substring using an optimized algorithm. Uniquely, it checks a local storage file (`testcases.txt`) to see if the string has been processed before. If the string is new, it saves the input and the result; if it exists, it notifies the user, ensuring an efficient history of test cases.

## 2. Methodology
The core solution utilizes the **Sliding Window Algorithm** to achieve linear time complexity, O(N), which is significantly faster than the O(N^2) brute-force approach.

* **Window Logic:** The algorithm maintains a "window" defined by `left` and `right` pointers.
* **Frequency Tracking:** An integer array `freq[256]` serves as a hash map to track character counts within the current window.
* **Dynamic Resizing:** As the `right` pointer expands the window, if a duplicate character is found, the `left` pointer advances to shrink the window until the duplicate is removed.

## 3. Challenges and Implementation Details
* **Complexity Management:** The primary challenge was optimizing the search for duplicates. By using a static frequency array of size 256 (covering standard ASCII), the space complexity is kept at O(1) while ensuring O(N) time complexity.
* **File Handling & Persistence:** Managing file I/O required careful handling of file pointers. The system uses `fopen` with mode `"r"` for reading to check for duplicates and mode `"a"` for appending new records. Input sanitization was also necessary to handle newline characters left by `fgets`.

## 4. Function Documentation

### `int lengthOfLongestSubstring(char *s)`
This is the core algorithmic function. It accepts the user's string and returns the integer length of the longest substring without repeating characters using the sliding window technique described in the methodology.

### `bool isinfile(const char* filename, const char* text)`
This utility function scans the persistent storage file (`testcases.txt`). It iterates through the file line-by-line using a buffer to determine if the user's input string has already been recorded. It returns `true` if a match is found, and `false` otherwise.

### `void addtotextfile(const char* filename, const char* text)`
Responsible for data persistence. This function opens the file in append mode. It first recalculates the result for the string and then writes both the string and its result to the file in a formatted structure.

### `int main()`
The entry point of the program. It manages the user interaction loop:
* Prompts the user for input (terminates on `**`).
* Validates input length and handles empty strings.
* Orchestrates the logic: Checks the file for duplicates -> Calculates Result -> Writes to file if new -> Prints output.

## 5. Installation and Execution

To run this project on your local machine, follow these steps:

### Clone the Repository
Open your terminal and clone the project files:
```bash
git clone [https://github.com/rayenbm04/longestsubstring_c](https://github.com/rayenbm04/longestsubstring_c)
cd longestsubstring_c
gcc main.c source.c -o main
./main

this should show up "Enter a string(enter ** to stop):" 
the programm will tell you to keep entering a string until you write the string "**" 


