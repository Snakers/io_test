#include "fopen_test.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

FileHandler* fopen_test(const char* path, const char* mode) {
    int flags = 0;
    if (strcmp(mode, "r") == 0) flags = O_RDONLY;
    else if (strcmp(mode, "w") == 0) flags = O_WRONLY | O_CREAT | O_TRUNC;
    else return NULL;

    int fd = open(path, flags, 0644);
    if (fd < 0) return NULL;

    FileHandler* h = malloc(sizeof(FileHandler));
    h->fd = fd;
    h->error = 0;
    h->eof = 0;
    return h;
}
