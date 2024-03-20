cmake_minimum_required(VERSION 3.27)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_practice main.cpp
        MyString/MyString.cpp
        MyString/MyString.h
        Complex/Complex.cpp
        Complex/Complex.h)
