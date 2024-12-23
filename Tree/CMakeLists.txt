cmake_minimum_required(VERSION 3.27)
project(Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tree main.cpp
        BinaryTree.h
        BinarySearchTree.h)
