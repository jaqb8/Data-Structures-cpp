//
// Created by kubaa on 14 Mar 2019.
//

#include "Heap.h"

Heap::Heap(int cap) {

    heap_size = 0;
    capacity = cap;
    items = new int[cap];
    for(int i = 0; i < capacity; i++) items[i] = 0;

}

Heap::~Heap() {
    delete [] items;
}

void Heap::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heap::ensure_extra_capacity() {
    if(heap_size == capacity) {
        int *temp = new int[capacity*2];
        for(int i = 0; i < capacity*2; i++) temp[i] = 0;
        for(int i = 0; i < capacity; i++) temp[i] = items[i];
        capacity *= 2;

        delete [] items;
        items = temp;
    }
}

int Heap::get_root() {
    if(heap_size == 0) throw(size_exc);
    return items[0];
}

int Heap::pop_root() {
    if(heap_size == 0) throw(size_exc);
    int item = items[0];
    items[0] = items[heap_size - 1];
    heap_size--;
    heapify_down();

    return item;
}

void Heap::add(int item) {
    ensure_extra_capacity();
    items[heap_size] = item;
    heap_size++;
    heapify_up();
}

void Heap::heapify_up() {
    int index = heap_size - 1;
    while(has_parent(index) && (parent(index) < items[index])) {
        swap(&items[get_parent_index(index)], &items[index]);
        index = get_parent_index(index);

    }
}

void Heap::heapify_down() {
    int index = 0;
    while(has_left_child(index)) {
        int smaller_child_index = get_left_child_index(index);
        if(has_right_child(index) && right_child(index) > left_child(index)) {
            smaller_child_index = get_right_child_index(index);
        }

        if(items[index] > items[smaller_child_index]) break;
        else swap(&items[index], &items[smaller_child_index]);

        index = smaller_child_index;
    }
}

void Heap::print_heap_arr() {
    for(int i = 0; i < heap_size; i++) std::cout << i+1 << ": " << items[i] << std::endl;
}

void Heap::print_2D_Util(int root, int space) {
    if(heap_size == 0) throw(size_exc);
    if(root > heap_size - 1) return;
    space += 10;

    print_2D_Util(get_right_child_index(root), space);

    for(int i = 10; i < space; i++) {
        std::cout << " ";
    }
    std::cout << items[root] << std::endl;

    print_2D_Util(get_left_child_index(root), space);

}

void Heap::print_2D(int root) {
    print_2D_Util(root, 0);
}




