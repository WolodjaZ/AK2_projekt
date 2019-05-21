//
// Created by vladimir on 05.05.19.
//

#ifndef C___THREADS_SUME_H
#define C___THREADS_SUME_H

#include <iostream>
#include <math.h>
#include <thread>
#include <mutex>
#include <chrono>   // For time()   // For srand() and rand()

class Sume {
private:
    int* tab;
    int size;
    double time1;


    std::thread* threadVect;
    std::mutex vectLock;
    int threads_size;

public:
    Sume(int size, int threadsSize);
    ~Sume();

    void start();

    void print();

    void pirnt_result();

    double time();

private:
    void add(int index, int length);
};


#endif //C___THREADS_SUME_H
