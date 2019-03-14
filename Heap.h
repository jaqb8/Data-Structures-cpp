//
// Created by kubaa on 14 Mar 2019.
//

#ifndef SDIZO_HEAP_H
#define SDIZO_HEAP_H
#include <iostream>


class Heap {
private:
    int *items; //pointer to an array of elements in heap
    int capacity; //max capacity of heap
    int heap_size; //current heap size
    void ensure_extra_capacity();
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

    std::string overflow_exc = "Overflow: Could not insert key.";
    std::string size_exc = "Heap not initialized!";

public:
    Heap(int cap);
    ~Heap();
    void add(int item);
    int get_root();
    int pop_root();
    void heapify_up();
    void heapify_down();
    void print_heap_arr();
    void print_2D(int root);



};


#endif //SDIZO_HEAP_H
