//
// Created by vladimir on 05.05.19.
//

#ifndef C___THREADS_MATRIX_H
#define C___THREADS_MATRIX_H

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>   // For time()   // For srand() and rand()

class Matrix {
private:
    int** first;
    int** second;
    int** result;
    int height_first;
    int height_second;
    double time1;

    std::thread* threadVect;
    std::mutex vectLock;
    int threads_size;

public:
    Matrix(int first_width, int first_height, int second_width, int second_height, int number_of_threads);
    ~Matrix();

    void start();

    void print_result();

    void print();

    double time();

private:
    void add(int index);
};


#endif //C___THREADS_MATRIX_H
