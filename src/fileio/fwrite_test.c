#include "fwrite_test.h"
#include <unistd.h>

size_t fwrite_test(const void* ptr, size_t size, size_t count, FileHandler* h) {
    ssize_t bytes = write(h->fd, ptr, size * count);
    if (bytes < 0) {
        h->error = 1;
        return 0;
    }
    return bytes / size;
}
