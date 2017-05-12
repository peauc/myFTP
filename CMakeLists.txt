cmake_minimum_required(VERSION 3.6)
project(myftp)

set(CMAKE_C_FLAGS "-W -Wall -Wextra")
#set(CMAKE_C_FLAGS_DEBUG  "-W -Wall -Wextra -g -gdb -O0")

include_directories(include)

file(GLOB_RECURSE SOURCE "src/*.c")
file(GLOB_RECURSE BOOTSTRAP "bootstrap/*")
file(GLOB_RECURSE INCLUDE "include/*.h")

add_executable(bootstrap ${BOOTSTRAP})
add_executable(myftp ${SOURCE} ${INCLUDE})
