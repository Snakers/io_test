#include <stdio.h>
#include <stdlib.h>
#include "test_cases.h"

int main(int argc, char* argv[]) {
    const char* filename;

    if (argc < 2) {
        filename = "temp_testfile.txt";
        printf("No file provided. Using default: %s\n", filename);
    } else {
        filename = argv[1];
    }

    run_all_tests(filename);

    // Optional cleanup
    if (remove(filename) == 0) {
        printf("Successfully Removed test file: %s\n", filename);
    } else {
        perror("⚠ Failed to remove test file");
    }

    return 0;
}
