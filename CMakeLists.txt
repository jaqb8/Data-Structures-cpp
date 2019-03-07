cmake_minimum_required(VERSION 3.13)
project(sdizo)

set(CMAKE_CXX_STANDARD 14)

add_executable(sdizo main.cpp DoublyLinkedList.cpp DoublyLinkedList.h Array.cpp Array.h)