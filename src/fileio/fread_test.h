#ifndef FREAD_TEST_H
#define FREAD_TEST_H

#include "fileHandler.h"
#include <stddef.h>

size_t fread_test(void* ptr, size_t size, size_t count, FileHandler* h);

#endif
