cmake_minimum_required(VERSION 3.13)
project(sdizo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++")

add_executable(sdizo main.cpp DoublyLinkedList.cpp DoublyLinkedList.h Array.cpp Array.h Heap.cpp Heap.h BinarySearchTree.cpp BinarySearchTree.h Test.cpp Test.h)