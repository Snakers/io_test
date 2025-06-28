#include "fopen_test.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t fread_test(void* ptr, size_t size, size_t count, FileHandler* h) {
    ssize_t bytes = read(h->fd, ptr, size * count);
    if (bytes < 0) {
        h->error = 1;
        return 0;
    }
    if (bytes == 0) h->eof = 1;
    return bytes / size;
}
