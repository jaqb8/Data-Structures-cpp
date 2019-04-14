//
// Created by kubaa on 14 Mar 2019.
//

#include <fstream>
#include "Heap.h"

Heap::Heap(int size) {

    heap_size = size;
    items = new int[heap_size];
    for(int i = 0; i < heap_size; i++) items[i] = 0;

}

Heap::~Heap() {
    delete [] items;
}

void Heap::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heap::add(int item) {
    heap_size++;
    int *temp = new int[heap_size];

    for(int i = 0; i < heap_size-1; i++) temp[i] = items[i];
    temp[heap_size-1] = item;

    delete [] items;
    items = temp;
    heapify_up(heap_size - 1);
}

void Heap::delete_item(int item) {
    if(!find(item)) throw(item_not_found_exc);

    int index = get_index(item);
    int replacement = items[heap_size-1];
    int replacement_parent = parent(index);

    swap(&items[heap_size-1], &items[index]);
    heap_size--;
    int *temp = new int[heap_size];

    for(int i = 0; i < heap_size; i++) temp[i] = items[i];
    delete [] items;
    items = temp;

    if(replacement > replacement_parent) heapify_up(index);
    else heapify_down(index);

}

void Heap::heapify_up(int index) {
    while(has_parent(index) && (parent(index) < items[index])) {
        swap(&items[get_parent_index(index)], &items[index]);
        index = get_parent_index(index);
    }
}

void Heap::heapify_down(int i) {
    int index = i;
    while(has_left_child(index)) {
        int greater_child_index = get_left_child_index(index);
        if(has_right_child(index) && (right_child(index) > left_child(index))) {
            greater_child_index = get_right_child_index(index);
        }

        if(items[index] > items[greater_child_index]) break;
        else swap(&items[index], &items[greater_child_index]);

        index = greater_child_index;
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

bool Heap::find(int item) {
    if(heap_size == 0) throw(size_exc);
    for(int i = 0; i < heap_size; i++) {
        if(items[i] == item) return true;
    }
    return false;
}

void Heap::generate_heap(int size, std::mt19937 generator) {
    std::uniform_int_distribution<uint32_t> r(1,100);
    if(size <= 0) throw(size_exc);

    heap_size = size;
    int *temp = new int[size];
    delete [] items;
    items = temp;

    for(int i = 0; i < size; i++) {
        int random = r(generator);
        items[i] = random;
    }

    create_heap();
}

void Heap::load_from_file(std::string file_name) {
    std::ifstream file(file_name);

    if(file.is_open()) {
        file >> heap_size;
        int *temp = new int[heap_size];
        delete [] items;
        items = temp;

        for(int i = 0; i < heap_size; i++) {
            file >> items[i];
        }

        create_heap();
        file.close();
    } else {
        throw(file_exc);
    }
}

void Heap::create_heap() {
    if(heap_size <= 0) throw(size_exc);

    for(int i = (heap_size-2)/2; i >= 0; --i) heapify_down(i);
}

int Heap::get_index(int item) {
    for(int i = 0; i < heap_size; i++) {
        if(items[i] == item) return i;
    }
}



