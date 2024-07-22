// Test file for stdout.c

// Include the Unity Test Framework
#include "unity.h"

// Include the header file to be tested
#include "stdout.h"

//Allowing the test file to access the source file
#include <stdio.h>

//Utility function to redirect stdout to a buffer
#include <stdlib.h>

// File descriptor manipulation
#include <unistd.h>

// Buffer to capture stdout
#define BUFFER_SIZE 1024
static char buffer[BUFFER_SIZE];

// Original stdout stream
static FILE* original_stdout;

void setUp(void) {
    // Redirect stdout to buffer

    fflush(stdout); // Flush stdout to write into the buffer
    original_stdout = freopen("test_output.txt", "w+", stdout); // Redirect stdout to a file
    if (original_stdout == NULL) { // Check if freopen failed
        perror("freopen failed"); // Print error message
        exit(EXIT_FAILURE);	// Exit the program
    }
    setvbuf(stdout, buffer, _IOFBF, BUFFER_SIZE); // Set buffer for stdout
}

void tearDown(void) {
    // Reset stdout to original

    fflush(stdout); // Flush stdout to write into the buffer
    dup2(fileno(original_stdout), STDOUT_FILENO); // Redirect stdout to original
    fclose(original_stdout); // Close the file
}

void test_print_hello(void) {
    print_hello(); // Call the function to be tested
    fflush(stdout); // Flush stdout to write into the buffer

    // Check if the output is as expected
    UNITY_TEST_ASSERT_EQUAL_STRING("Hello, World!\n", buffer, __LINE__, "Expected output does not match.");
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_print_hello);
    return UNITY_END();
}