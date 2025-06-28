#include "fclose_test.h"
#include <unistd.h>
#include <stdlib.h>

int fclose_test(FileHandler* h) {
    if (!h) return -1;
    int res = close(h->fd);
    free(h);
    return res;
}
