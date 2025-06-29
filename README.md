# File I/O Test Suite (`iotest`)

This project is a minimal test suite for validating a custom implementation of standard C file I/O functions using system-level POSIX APIs (`open`, `read`, `write`, `close`). It is designed as a technical assignment for a Software Testing Engineer position.

## Purpose

The goal is to test these reimplemented standard functions:

- `fopen`
- `fread`
- `fwrite`
- `fclose`
- `feof`
- `ferror`

Each function is backed by corresponding system calls:
- `fopen` → `open`
- `fread` → `read`
- `fwrite` → `write`
- `fclose` → `close`

---

## 🛠 Structure
```
├── CMakeLists.txt
├── src/
│ ├── fileio/
│ │ ├── fopen_test.{c,h}
│ │ ├── fread_test.{c,h}
│ │ ├── fwrite_test.{c,h}
│ │ ├── fclose_test.{c,h}
│ │ ├── ferror_test.{c,h}
│ │ └── fileHandler.h
│ └── test/
│ ├── main.c
│ ├── test_cases.c
│ └── test_cases.h
```


---

## 🚀 Build Instructions
### 1. Clone the repo

```
git clone git@github.com:Snakers/io_test.git
cd io_test
```

2. Build the project

```
mkdir build && cd build
cmake ..
make
```

3. Run the tests

```
./iotest               # uses default file
./iotest myfile.txt    # uses a custom test file
```

4.You can also run CTest:
```
ctest
```

##Note: You can call ctest by splitting each test in a saparate main file. 

But you need to modify cmakelists similar to:
```
cmake_minimum_required(VERSION 3.10)
project(MyIOTest)

set(CMAKE_C_STANDARD 99)

add_library(myio myio.c)

add_executable(test_open_write main_open_write.c)
target_link_libraries(test_open_write myio)
add_test(NAME TestOpenWrite COMMAND test_open_write)

add_executable(test_read main_read.c)
target_link_libraries(test_read myio)
add_test(NAME TestRead COMMAND test_read)

add_executable(test_eof main_eof.c)
target_link_libraries(test_eof myio)
add_test(NAME TestEOF COMMAND test_eof)

add_executable(test_error main_error.c)
target_link_libraries(test_error myio)
add_test(NAME TestError COMMAND test_error)
```

By splitting each test case in a Main function as you can see in the cmake we add executable and add_test uses each main by its command. 
