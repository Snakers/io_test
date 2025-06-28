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
