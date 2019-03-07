//
// Created by kubaa on 4 Mar 2019.
//

#include <iostream>
#include <fstream>
#include <random>
#include "DoublyLinkedList.h"


DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::DoublyLinkedList(int length) {
    int data;
    Node* new_node;

    if(length > 0) {
        std::cout << "Podaj wartosc dla pierwszego wezla: ";
        std::cin >> data;
        head = new Node(data);

        // first node
        if(head != nullptr) {
            head->previous = nullptr;
            head->next = nullptr;
            tail = head;
        }

        // rest of n-1 nodes
        for(int i = 2; i <= length; i++) {
            std::cout << "Podaj wartosc dla wezla nr " << i << ": ";
            std::cin >> data;
            new_node = new Node(data);

            if(new_node != nullptr) {
                new_node->previous = tail;
                new_node->next = nullptr;
                tail->next = new_node;
                tail = new_node;
            }
        }
    }
    std::cout << "Pomyslnie utworzono liste!" << std::endl;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* to_delete;

    while(head != nullptr) {
        to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

void DoublyLinkedList::print_forward() {
    Node* temp = head;

    while(temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::print_backward() {
    Node* temp = tail;

    while(temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->previous;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::insert_front(int data) {
    Node* new_node;

    if(head == nullptr) std::cout << "Blad, lista jest pusta." << std::endl;
    else {
        new_node = new Node(data);
        new_node->previous = nullptr;
        new_node->next = head;
        head->previous = new_node;
        head = new_node;

        std::cout << "Pomyslnie dodatno wezel na poczatek listy." << std::endl;
    }
}

void DoublyLinkedList::insert_end(int data) {
    Node* new_node;

    if(tail == nullptr) std::cout << "Blad, lista jest pusta." << std::endl;
    else {
        new_node = new Node(data);
        new_node->previous = tail;
        new_node->next = nullptr;
        tail->next = new_node;
        tail = new_node;

        std::cout << "Pomyslnie dodano wezel na koniec listy." << std::endl;
    }
}

void DoublyLinkedList::insert_at(int data, int position) {
    Node* new_node;
    Node* temp;
    int i;

    if(head == nullptr) std::cout << "Blad, lista jest pusta." << std::endl;
    else {
        temp = head;
        i = 1;

        // set position of temp
        while(i < position-1 && temp != nullptr) {
            temp = temp->next;
            i++;
        }

        if(position == 1) insert_front(data);
        else if(temp == tail) insert_end(data);
        else if(temp != nullptr) {
            new_node = new Node(data);
            new_node->previous = temp;
            new_node->next = temp->next;

            if(temp->next != nullptr) {
                temp->next->previous = new_node;
            }

            temp->next = new_node;

            std::cout << "Pomyslnie dodano wezel na pozycji nr " << position << "." << std::endl;
        } else {
            std::cout << "Blad, nieprawidlowa pozycja." << std::endl;
        }
    }
}

void DoublyLinkedList::delete_front() {
    Node* to_delete;

    if(head == nullptr) std::cout << "Blad, lista jest pusta." << std::endl;
    else {
        to_delete = head;
        head = head->next; // 2nd node is now head
        if(head != nullptr) head->previous = nullptr; // remove link to previous node
        delete to_delete;

        std::cout << "Pomyslnie usunieto wezel z poczatku listy." << std::endl;
    }
}

void DoublyLinkedList::delete_end() {
    Node* to_delete;

    if(tail == nullptr) std::cout << "Blad, lista jest pusta." << std::endl;
    else {
        to_delete = tail;
        tail = tail->previous;
        if(tail != nullptr) tail->next = nullptr;
        delete to_delete;

        std::cout << "Pomyslnie usunieto wezel z konca listy." << std::endl;
    }
}

void DoublyLinkedList::delete_at(int position) {
    Node* current;
    int i;

    current = head;

    // set position of current
    for(i = 1; i < position && current != nullptr; i++) {
        current = current->next;
    }

    if(position == 1) delete_front();
    else if(current == tail) delete_end();
    else if(current != nullptr){
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;

        std::cout << "Pomyslnie usunieto wezel na pozycji nr " << position << "." << std::endl;
    } else {
        std::cout << "Blad, nieprawidlowa pozycja." << std::endl;
    }
}

void DoublyLinkedList::find(int to_find) {
    Node* current;
    current = head;

    while(current != nullptr) {
        if(current->data == to_find) {
            std::cout << "Znaleziono podana wartosc." << std::endl;
            return;
        }
        else current = current->next;
    }
    std::cout << "Nie znaleziono podanej wartosci." << std::endl;
}

void DoublyLinkedList::load_from_file(std::string filename) {
    std::ifstream file(filename);
    Node* new_node;
    int size, data;

    if(file.is_open()) {
        file >> size;
        std::cout << size << " - size" << std::endl;
        file >> data;
        std::cout << data << " - data1" << std::endl;
        head = new Node(data);
        std::cout << "lll" << std::endl;

        if(head != nullptr) {
            head->previous = nullptr;
            head->next = nullptr;
            tail = head;
        }

        for(int i = 2; i <= size; i++) {
            file >> data;
            std::cout << data << " - data" << std::endl;
            new_node = new Node(data);
            new_node->previous = tail;
            new_node->next = nullptr;
            tail->next = new_node;
            tail = new_node;
        }
        file.close();
    }
}

void DoublyLinkedList::generate_list(int size, std::mt19937 generator) {
    std::uniform_int_distribution<uint32_t> r(1,100);
    int random = r(generator);
    Node* new_node;

    if(size > 0) {
        head = new Node(random);

        if(head != nullptr) {
            head->previous = nullptr;
            head->next = nullptr;
            tail = head;
        }

        for(int i = 2; i <= size; i++) {
            random = r(generator);
            new_node = new Node(random);

            new_node->previous = tail;
            new_node->next = nullptr;
            tail->next = new_node;
            tail = new_node;
        }
    }
}
