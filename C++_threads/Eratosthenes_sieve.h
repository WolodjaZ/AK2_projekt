//
// Created by vladimir on 05.05.19.
//

#ifndef C___THREADS_ERATOSTHENES_SIEVE_H
#define C___THREADS_ERATOSTHENES_SIEVE_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <vector>

class Eratosthenes_sieve {
private:
    int *tab;
    double time1;
    int size;
    //std::thread* threadVect;
    std::vector<std::thread> threadVect;
    int thread_size;

    bool* inUse;

    std::mutex vectLock;

public:
    Eratosthenes_sieve(int interval, int thread_size);
    ~Eratosthenes_sieve();

    void start();

    void change(int interval, int thread_size);


    void print();

    double time();

private:
    void first_numbers(int index);


};


#endif //C___THREADS_ERATOSTHENES_SIEVE_H
