//
// Created by kubaa on 30 Mar 2019.
//

#ifndef SDIZO_BINARYSEARCHTREE_H
#define SDIZO_BINARYSEARCHTREE_H

#include <random>

class Node {
public:
    int key;
    Node *left;
    Node *right;
    Node *parent;
    Node(int k) {key = k; left = nullptr; right = nullptr; parent = nullptr;}
};

class BinarySearchTree {
private:
//    struct Node {
//        int key;
//        Node *left;
//        Node *right;
//        Node *parent;
//        Node(int d) : key(d), left(nullptr), right(nullptr), parent(nullptr) {};
//    };

    Node *root;
    void print_2D_Util(Node *r, int space);
    Node* search(Node *to_find, int key);
    Node* min_key(Node *to_find);
    Node* max_key(Node *to_find);
    Node* find_successor(Node *node);
    Node* find_predecessor(Node *node);
    void destroy(Node *root);

    std::string node_not_found_exc = "Nie znaleziono podanej wartosci!";
    std::string file_exc = "Blad! Plik nie zostal otwarty.";
    std::string size_exc = "Blad!";

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert_node(int key);
    void print_2D();
    bool find(int key);
    void delete_node(int key);
    void load_from_file(std::string file_name);
    void generate_bst(int size, std::mt19937 generator);

};


#endif //SDIZO_BINARYSEARCHTREE_H
