cmake_minimum_required(VERSION 3.10)
project(iotest C)

set(CMAKE_C_STANDARD 11)

enable_testing()

include_directories(src/fileio src/test)

file(GLOB FILEIO_SRC src/fileio/*.c)
file(GLOB TEST_SRC src/test/*.c)

add_custom_target(test-run
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS iotest
)
add_executable(iotest ${FILEIO_SRC} ${TEST_SRC})

# Add for ctest (optional)
add_test(NAME RunIOTests COMMAND iotest temp_testfile.txt)
