//
// Created by kubaa on 3 Apr 2019.
//

#ifndef SDIZO_TEST_H
#define SDIZO_TEST_H

#include <chrono>

using namespace std;

class Test {
public:
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock ::time_point end;
    void begin() {
        start = chrono::high_resolution_clock::now();
    }

    void stop() {
        end = chrono::high_resolution_clock::now();
    }

    long timeElapsed() {
        return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    }
};


#endif //SDIZO_TEST_H
