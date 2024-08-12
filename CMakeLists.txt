cmake_minimum_required(VERSION 3.30)
project(fibGen5)

find_package(gmp REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)

#target_include_directories(include PUBLIC ./src/include)

target_link_libraries(${PROJECT_NAME} gmp::gmp)

add_subdirectory(src/include)