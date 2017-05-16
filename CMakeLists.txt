cmake_minimum_required(VERSION 3.6)
project(myftp)

set(CMAKE_C_FLAGS "-W -Wall -Wextra")

include_directories(include)

file(GLOB_RECURSE SOURCE "src/*.c")
file(GLOB_RECURSE INCLUDE "include/*.h")

add_executable(myftp ${SOURCE} ${INCLUDE})
