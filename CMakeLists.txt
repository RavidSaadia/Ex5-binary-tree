cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DEMO
        Demo.cpp BinaryTree.hpp)


add_executable(TEST
        Test.cpp doctest.h TestCounter.cpp BinaryTree.hpp)


add_executable(TEST1
        StudentTest1.cpp doctest.h TestRunner.cpp BinaryTree.hpp)

add_executable(TEST2
        StudentTest2.cpp doctest.h TestRunner.cpp BinaryTree.hpp)

add_executable(TEST3
        StudentTest3.cpp doctest.h TestRunner.cpp BinaryTree.hpp)