//
// Created by kubaa on 30 Mar 2019.
//

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

void BinarySearchTree::insert_node(int key) {
    Node *new_node = new Node(key);
    Node *parent = nullptr;
    Node *temp = root;

    while(temp != nullptr) {
        parent = temp;
        if(new_node->key < temp->key) temp = temp->left;
        else temp = temp->right;
    }

    new_node->parent = parent;

    if(parent == nullptr) root = new_node;
    else {
        if(new_node->key < parent->key) parent->left = new_node;
        else parent->right = new_node;
    }
}

void BinarySearchTree::print_2D_Util(Node *r, int space) {
    if(r == nullptr) return;
    space += 10;

    print_2D_Util(r->right, space);
    std::cout << std::endl;

    for(int i = 10; i < space; i++) {
        std::cout << " ";
    }
    std::cout << r->key << std::endl;

    print_2D_Util(r->left, space);
}

void BinarySearchTree::print_2D() {
    print_2D_Util(root, 0);
}

Node* BinarySearchTree::search(Node *to_find, int key) {
    if(to_find == nullptr || to_find->key == key) return to_find;
    if(key < to_find->key) return search(to_find->left, key);
    return search(to_find->right, key);
}

bool BinarySearchTree::find(int key) {
    if(search(root, key) != nullptr) return true;
    return false;
}

Node* BinarySearchTree::min_key(Node *to_find) {
    while(to_find->left != nullptr) {
        to_find = to_find->left;
    }
    return to_find;
}

Node* BinarySearchTree::max_key(Node *to_find) {
    while(to_find->right != nullptr) {
        to_find = to_find->right;
    }
    return to_find;
}

Node* BinarySearchTree::find_successor(Node *node) {
    if(node->right != nullptr) return min_key(node->right);
    Node *temp = node->parent;

    while(temp != nullptr && temp->left != node) {
        node = temp;
        temp = temp->parent;
    }
    return temp;
}

Node* BinarySearchTree::find_predecessor(Node *node) {
    if(node->left != nullptr) return max_key(node->left);
    Node *temp = node->parent;

    while(temp != nullptr && temp->right != node) {
        node = temp;
        temp = temp->parent;
    }
    return temp;
}

void BinarySearchTree::delete_node(int key) {
    if(search(root, key) == nullptr) throw(node_not_found_exc);

    Node *to_delete = search(root, key);
    Node *succ;
    Node *child;
    if(to_delete->left == nullptr || to_delete->right == nullptr) succ = to_delete;
    else succ = find_successor(to_delete);

    if(succ->left != nullptr) child = succ->left;
    else child = succ->right;

    if(child != nullptr) child->parent = succ->parent;

    if(succ->parent == nullptr) root = child;
    else {
        if(succ == succ->parent->left) succ->parent->left = child;
        else succ->parent->right = child;
    }

    if(succ != to_delete) {
        to_delete->key = succ->key;
    }

    delete succ;
}

void BinarySearchTree::destroy(Node *root) {
    if(root == nullptr) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

void BinarySearchTree::load_from_file(std::string file_name) {
    std::ifstream file(file_name);

    if(file.is_open()) {
        int size;
        file >> size;

        for(int i = 0; i < size; i++) {
            int key;
            file >> key;
            insert_node(key);
        }

        file.close();
    } else {
        throw(file_exc);
    }
}

void BinarySearchTree::generate_bst(int size, std::mt19937 generator) {
    std::uniform_int_distribution<uint32_t> r(1,100);
    if(size <= 0) throw(size_exc);

    for(int i = 0; i < size; i++) {
        int random = r(generator);
        insert_node(random);
    }
}








