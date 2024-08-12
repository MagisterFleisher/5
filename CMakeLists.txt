cmake_minimum_required(VERSION 3.30)
project(fibGen5 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(gmp REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE gmp::gmp Threads::Threads)

add_subdirectory(src/include)