cmake_minimum_required(VERSION 3.22)
project(agama CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(agama main.cpp WriterMonad.h OptionMonad.h)

find_package(fmt CONFIG REQUIRED)
    target_link_libraries(agama PRIVATE fmt::fmt)