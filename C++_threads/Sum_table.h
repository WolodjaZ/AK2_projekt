//
// Created by vladimir on 05.05.19.
//

#ifndef C___THREADS_SUM_TABLE_H
#define C___THREADS_SUM_TABLE_H

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Sum_table {
private:
    int **tab;
    double time1;
    int size;
    int number_of_tables;
    std::thread* threadVect;
    int thread_size;

    std::mutex vectLock;

public:
    Sum_table(int size, int numberOfTables, int threadSize);
    ~Sum_table();

    void start();

    void print();

    void print_result();

    double time();

private:
    void add(int start, int end);
};


#endif //C___THREADS_SUM_TABLE_H
