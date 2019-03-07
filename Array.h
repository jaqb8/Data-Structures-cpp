//
// Created by kubaa on 6 Mar 2019.
//

#include <random>
#ifndef SDIZO_ARRAY_H
#define SDIZO_ARRAY_H


class Array {
private:
    int *arr;
    int size;

public:
    Array();
    Array(int size);
    ~Array();
    void print();
    void insert_front(int data);
    void insert_end(int data);
    void insert_at(int data, int position);
    void delete_front();
    void delete_end();
    void delete_at(int position);
    bool find(int data);
    void load_from_file(std::string filename);
    void generate_array(int s, std::mt19937 generator);

};


#endif //SDIZO_ARRAY_H
