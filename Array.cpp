//
// Created by kubaa on 6 Mar 2019.
//

#include <iostream>
#include <fstream>
#include <random>
#include "Array.h"

Array::Array() {
    arr = nullptr;
    size = 0;
}

Array::Array(int s) {
    size = s;
    arr = new int[size];
    for(int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

Array::~Array() {
    delete [] arr;
}

void Array::print() {
    if(arr != nullptr || size != 0) {
        for(int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    } else {
        //throw("Array not initialized!");
    }
}

void Array::insert_front(int data) {
    if(arr != nullptr || size != 0) {
        int* temp = new int[size+1];
        temp[0] = data;
        for(int i = 1; i < size+1; i++) {
            temp[i] = arr[i-1];
        }

        delete [] arr;
        size++;
        arr = temp;
    }
}

void Array::insert_end(int data) {
    if(arr != nullptr || size != 0) {
        int* temp = new int[size+1];
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        temp[size] = data;

        delete [] arr;
        size++;
        arr = temp;
    }
}

void Array::insert_at(int data, int position) {
    if(arr != nullptr || size != 0) {
        if(position == 0) insert_front(data);
        else if(position == size-1) insert_end(data);
        else {
            if(position >= 0 && position <= size-1) {
                int* temp = new int[size+1];
                for(int i = 0; i < size+1; i++) {
                    if(i < position) temp[i] = arr[i];
                    else if (i == position) temp[i] = data;
                    else if (i > position) temp[i] = arr[i-1];
                }

                delete [] arr;
                size++;
                arr = temp;
            } else {
                //throw("Wrong index!");
            }
        }
    } else {
        //throw("Array not initialized!");
    }
}

void Array::delete_front() {
    if(arr != nullptr || size != 0) {
        int* temp = new int[size--];
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i+1];
        }

        delete [] arr;
        arr = temp;
    } else {
        throw("Array not initialized!");
    }
}

void Array::delete_end() {
    if(arr != nullptr || size != 0) {
        int* temp = new int[size--];
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        delete [] arr;
        arr = temp;
    } else {
        throw("Array not initialized!");
    }
}

void Array::delete_at(int position) {
    if(arr != nullptr || size != 0) {
        if (position == 0) delete_front();
        else if (position == size - 1) delete_end();
        else {
            if (position >= 0 && position <= size-1) {
                int *temp = new int[size--];
                for (int i = 0; i < size; i++) {
                    if (i < position) temp[i] = arr[i];
                    if (i >= position) temp[i] = arr[i + 1];
                }

                delete [] arr;
                arr = temp;
            } else {
                throw ("Wrong index!");
            }
        }
    } else {
        throw("Array not initialized!");
    }
}

bool Array::find(int data) {
    if (arr != nullptr || size != 0) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == data) return true;
        }
        return false;
    } else {
        throw("Array not initialized!");
    }
}

void Array::load_from_file(std::string filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        file >> size;
        int* temp = new int[size];

        for (int i = 0; i < size; i++) {
            file >> temp[i];
        }

        delete [] arr;
        arr = temp;

        file.close();
    }

}

void Array::generate_array(int s, std::mt19937 generator) {
    std::uniform_int_distribution<uint32_t> r(1,100);

    if (s > 0) {
        size = s;
        int* temp = new int[size];

        for(int i = 0; i < size; i++) {
            int random = r(generator);
            temp[i] = random;
        }

        delete [] arr;
        arr = temp;
    } else {
        throw("Wrong size!");
    }
}

