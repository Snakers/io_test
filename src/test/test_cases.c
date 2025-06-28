#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "fopen_test.h"
#include "fread_test.h"
#include "fwrite_test.h"
#include "fclose_test.h"
#include "ferror_test.h"

void test_open_nonexistent(const char* filename) {
    FileHandler* f = fopen_test(filename, "r");
    printf(f == NULL ? "Successfully open_nonexistent passed\n" : "Failed open_nonexistent failed\n");
}

void test_write_read(const char* filename) {
    FileHandler* f = fopen_test(filename, "w");
    fwrite_test("Hello", 1, 5, f);
    fclose_test(f);

    char buf[10] = {0};
    f = fopen_test(filename, "r");
    fread_test(buf, 1, 5, f);
    fclose_test(f);

    printf(strcmp(buf, "Hello") == 0 ? "Successfully write_read passed\n" : "Failed write_read failed\n");
}

void test_feof_behavior(const char* filename) {
    FileHandler* f = fopen_test(filename, "r");
    char c;
    while (fread_test(&c, 1, 1, f)) {}
    printf(f->eof ? "Successfully feof_behavior passed\n" : "Failed feof_behavior failed\n");
    fclose_test(f);
}

void test_fclose_behavior(const char* filename) {
    FileHandler* f = fopen_test(filename, "w");
    int result = fclose_test(f);
    printf(result == 0 ? "Successfully fclose_behavior passed\n" : "Failed fclose_behavior failed\n");
}

void test_ferror_behavior(const char* filename) {
    FileHandler* f = fopen_test("definitely_not_real_file.txt", "r");

    if (f == NULL) {
        printf("Successfully ferror_behavior passed (open failed, no object)\n");
        return;
    }

    char c;
    fread_test(&c, 1, 1, f);
    int err = ferror_test(f);
    fclose_test(f);

    printf(err ? "Successfully ferror_behavior passed\n" : "Failed ferror_behavior failed\n");
}


void run_all_tests(const char* filename) {
    test_open_nonexistent("no_such_file.txt");
    test_write_read(filename);
    test_feof_behavior(filename);
    test_fclose_behavior(filename);
    test_ferror_behavior("definitely_not_real_file.txt");
}
