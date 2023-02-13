cmake_minimum_required(VERSION 3.24)
project(ex01)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex01 main.cpp Contact.class.hpp Contact.class.cpp PhoneBook.class.hpp PhoneBook.class.cpp)
