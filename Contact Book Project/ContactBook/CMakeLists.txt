cmake_minimum_required(VERSION 3.29)
project(ContactBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(ContactBook main.cpp
        DynamicArray.h
        Address.h
        Person.h
        PrintingContactBook.h
        ContactBookOperations.h)
