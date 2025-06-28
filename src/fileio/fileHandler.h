#ifndef FILEHANDLER_H
#define FILEHANDLER_H

typedef struct FileHandler {
    int fd;
    int error;
    int eof;
} FileHandler;

#endif
