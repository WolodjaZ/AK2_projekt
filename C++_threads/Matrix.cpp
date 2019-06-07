//
// Created by vladimir on 28.04.19.
//


#include "Matrix.h"

Matrix::Matrix(int first_width, int first_height, int second_width, int second_height, int number_of_threads) : height_first(first_height), height_second(second_height), threads_size(number_of_threads){
    srand(std::time(NULL));

    first = new int* [first_height];
    second = new int* [second_height];
    result = new int* [first_height];
    threadVect = new std::thread [number_of_threads];

    for(int a = 0; a < first_height; a++){
        first[a] = new int [first_width];
        for(int i = 0; i < first_width; i++)
            first[a][i] = std::rand() % 101;
    }



    for(int a = 0; a < second_height; a++){
        second[a] = new int [second_width];
        for(int i = 0; i < second_width; i++)
            second[a][i] = std::rand() % 101;
    }


    for(int a = 0; a < first_height; a++){
        result[a] = new int [second_width];
        for(int i = 0; i < second_width; i++){
            result[a][i] = 0;
        }
    }
}

Matrix::~Matrix() {
    for(int a = 0; a < height_first; a++){
        delete[] first[a];
        delete[] result[a];
    }

    for(int a = 0; a < height_second; a++) delete [] second[a];

    delete[] first;
    delete[] second;
    delete[] result;
    delete[] threadVect;
}

void Matrix::start() {
    auto start = std::chrono::system_clock::now();
    for(int a = 0; a < threads_size; a++) {
        //threadVect[a] = std::thread(std::bind(&Matrix::add, this, a));
        threadVect[a] = std::thread(&Matrix::add, this, a);
    }

    for(int a = 0; a < threads_size; a++){
        //if(threadVect[a].joinable())
        threadVect[a].join();
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    time1 = elapsed_seconds.count();


}

void Matrix::add(int index) {
    if(index >= height_first){
        return;
    }
    //std::cout << index << " " << height_first << std::endl;
    for(int a = 0; a < height_first; a++){
        int wynik = 0;
        for(int b = 0; b < height_second; b++){
            wynik = wynik + first[index][b]*second[b][a];
        }

        //vectLock.lock();
        result[index][a] = wynik;
        //vectLock.unlock();
        //std::cout <<  result[index][a] << " " << index << " " << a <<std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    add(index+threads_size);
}

void Matrix::print() {
    std::cout << "Pirwszy Matrix:" << std::endl;
    for(int a = 0; a < height_first; a++){
        for(int i = 0; i < height_second; i++){
            std::cout << first[a][i] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "Drugi Matrix:" << std::endl;
    for(int a = 0; a < height_second; a++){
        for(int i = 0; i < height_first; i++){
            std::cout << second[a][i] << " ";
        }

        std::cout << std::endl;
    }
}


void Matrix::print_result() {
    std::cout << "Wynik Matrix:" << std::endl;
    for(int a = 0; a < height_first; a++){
        for(int i = 0; i < height_first; i++){
            std::cout << result[a][i] << " ";
        }

        std::cout << std::endl;

    }

    std::cout << "Time: " << time1*1000 << " in [ms]" << std::endl;
}

double Matrix::time() {
    return time1;
}