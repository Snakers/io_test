#ifndef FWRITE_TEST_H
#define FWRITE_TEST_H

#include "fileHandler.h"
#include <stddef.h>

size_t fwrite_test(const void* ptr, size_t size, size_t count, FileHandler* h);

#endif
