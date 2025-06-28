#include "ferror_test.h"

int ferror_test(FileHandler* h) {
    return h ? h->error : 1;
}
