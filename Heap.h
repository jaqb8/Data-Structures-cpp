//
// Created by kubaa on 14 Mar 2019.
//

#ifndef SDIZO_HEAP_H
#define SDIZO_HEAP_H
#include <iostream>
#include <random>


class Heap {
private:
    int *items; //pointer to an array of elements in heap
    int heap_size; //current heap size
    void swap(int *a, int *b);

    int get_parent_index(int child_index) { return (child_index - 1) / 2; };
    int get_left_child_index(int parent_index) { return (2 * parent_index) + 1; };
    int get_right_child_index(int parent_index) { return (2 * parent_index) + 2; };

    bool has_left_child(int index) { return get_left_child_index(index) < heap_size; };
    bool has_right_child(int index) { return get_right_child_index(index) < heap_size; };
    bool has_parent(int index) { return get_parent_index(index) >= 0; };

    int left_child(int index) { return items[get_left_child_index(index)]; };
    int right_child(int index) { return items[get_right_child_index(index)]; };
    int parent(int index) { return items[get_parent_index(index)]; };

    void print_2D_Util(int root, int space);
    void heapify_up(int index);
    void heapify_down(int i);
    void create_heap();
    int get_index(int item);

    std::string size_exc = "Heap not initialized!";
    std::string file_exc = "Error - file not opened!";
    std::string item_not_found_exc = "Error - item not found!";

public:
    Heap(int cap);
    ~Heap();
    void add(int item);
    void delete_item(int item);
    bool find(int item);
    void generate_heap(int size, std::mt19937 generator);
    void print_heap_arr();
    void print_2D(int root = 0);
    void load_from_file(std::string file_name);



};


#endif //SDIZO_HEAP_H
