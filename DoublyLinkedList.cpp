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

//DoublyLinkedList::DoublyLinkedList(int length) {
//    int data;
//    Node* new_node;
//
//    if(length > 0) {
//        std::cout << "Podaj wartosc dla pierwszego wezla: ";
//        std::cin >> data;
//        head = new Node(data);
//
//        // first node
//        if(head != nullptr) {
//            head->previous = nullptr;
//            head->next = nullptr;
//            tail = head;
//        }
//
//        // rest of n-1 nodes
//        for(int i = 2; i <= length; i++) {
//            std::cout << "Podaj wartosc dla wezla nr " << i << ": ";
//            std::cin >> data;
//            new_node = new Node(data);
//
//            if(new_node != nullptr) {
//                new_node->previous = tail;
//                new_node->next = nullptr;
//                tail->next = new_node;
//                tail = new_node;
//            }
//        }
//    }
//    std::cout << "Pomyslnie utworzono liste!" << std::endl;
//}

DoublyLinkedList::~DoublyLinkedList() {
    Node* to_delete;
    while(head != nullptr) {
        to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

void DoublyLinkedList::print_forward() {

    if (head != nullptr) {
        Node* temp = head;
        while(temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    } else {
        throw(not_init_exc);
    }

}

void DoublyLinkedList::print_backward() {

    if (tail != nullptr) {
        Node* temp = tail;
        while(temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->previous;
        }
    } else {
        throw(not_init_exc);
    }


}

void DoublyLinkedList::insert_front(int data) {
    Node* new_node;

    new_node = new Node(data);
    new_node->previous = nullptr;
    new_node->next = head;

    if(head != nullptr) {
        head->previous = new_node;
    } else {
        tail = new_node;
    }

    head = new_node;

}

void DoublyLinkedList::insert_end(int data) {
    Node* new_node;

    if(tail == nullptr) throw(not_init_exc);
    else {
        new_node = new Node(data);
        new_node->previous = tail;
        new_node->next = nullptr;
        tail->next = new_node;
        tail = new_node;

    }
}

void DoublyLinkedList::insert_at(int data, int position) {
    Node* new_node;
    Node* temp;
    int i;


    temp = head;
    i = 1;

    // set position of temp
    while(i < position && temp != nullptr) {
        temp = temp->next;
        i++;
    }

    if(position == 0) insert_front(data);
    else if(temp == tail) insert_end(data);
    else if(temp != nullptr) {
        new_node = new Node(data);
        new_node->previous = temp;
        new_node->next = temp->next;

        if(temp->next != nullptr) {
            temp->next->previous = new_node;
        }

        temp->next = new_node;

    } else {
        throw(position_exc);
    }

}

void DoublyLinkedList::delete_front() {
    Node* to_delete;

    if(head == nullptr) throw(not_init_exc);
    else {
        to_delete = head;
        head = head->next; // 2nd node is now head
        if(head != nullptr) head->previous = nullptr; // remove link to previous node
        delete to_delete;
    }
}

void DoublyLinkedList::delete_end() {
    Node* to_delete;

    if(tail == nullptr) throw(not_init_exc);
    else {
        to_delete = tail;
        tail = tail->previous;
        if(tail != nullptr) tail->next = nullptr;
        else head = nullptr;
        delete to_delete;
    }
}

void DoublyLinkedList::delete_node(int value) {

    if(!find(value)) throw(not_found);

    if (head != nullptr) {
        Node *current;
        current = head;

        while(current != nullptr) {
            if(current->data == value) {
                if(current->next == nullptr) {
//                    tail = tail->previous;
//                    if(tail != nullptr) tail->next = nullptr;
//                    delete current;
                        delete_end();
                        return;
                }
                else if(current->previous == nullptr) {
//                    head = head->next;
//                    if(head != nullptr) head->previous = nullptr;
//                    delete current;
                        delete_front();
                        return;
                }
                else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    delete current;
                    return;
                }
            } else {
                current = current->next;
            }
        }
    } else {
        throw(not_init_exc);
    }
}

bool DoublyLinkedList::find(int to_find) {

    if (head != nullptr) {
        Node *current;
        current = head;

        while (current != nullptr) {
            if (current->data == to_find) {
                return true;
            } else current = current->next;
        }
        return false;
    } else {
        throw(not_init_exc);
    }
}

void DoublyLinkedList::load_from_file(std::string filename) {
    // delete old list
    Node* to_delete;
    while(head != nullptr) {
        to_delete = head;
        head = head->next;
        delete to_delete;
    }

    std::ifstream file(filename);
    Node* new_node;
    int size, data;

    if(file.is_open()) {
        file >> size;
        file >> data;
        head = new Node(data);

        if(head != nullptr) {
            head->previous = nullptr;
            head->next = nullptr;
            tail = head;
        }

        for(int i = 2; i <= size; i++) {
            file >> data;
            new_node = new Node(data);
            new_node->previous = tail;
            new_node->next = nullptr;
            tail->next = new_node;
            tail = new_node;
        }
        file.close();
    } else {
        throw(file_exc);
    }
}

void DoublyLinkedList::generate_list(int size, std::mt19937 generator) {
    // delete old list
    Node* to_delete;
    while(head != nullptr) {
        to_delete = head;
        head = head->next;
        delete to_delete;
    }

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
    } else {
        throw(size_exc);
    }
}
