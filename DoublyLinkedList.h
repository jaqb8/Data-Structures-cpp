//
// Created by kubaa on 4 Mar 2019.
//
#include <iostream>
#include <random>
#ifndef SDIZO_DOUBLYLINKEDLIST_H
#define SDIZO_DOUBLYLINKEDLIST_H


class DoublyLinkedList {

private:
    struct Node {
        int data;
        Node* previous;
        Node* next;
        Node(int d) : data(d), previous(nullptr), next(nullptr) {};
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    DoublyLinkedList(int length);
    ~DoublyLinkedList();
    void print_forward();
    void print_backward();
    void insert_front(int data);
    void insert_end(int data);
    void insert_at(int data, int position);
    void delete_front();
    void delete_end();
    void delete_at(int position);
    void find(int to_find);
    void load_from_file(std::string filename);
    void generate_list(int size, std::mt19937 generator);

};


#endif //SDIZO_DOUBLYLINKEDLIST_H