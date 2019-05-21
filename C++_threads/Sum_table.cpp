//
// Created by vladimir on 05.05.19.
//

#include "Sum_table.h"

Sum_table::Sum_table(int size, int numberOfTables, int threadSize) : size(size), number_of_tables(numberOfTables),
                                                                     thread_size(threadSize) {

    srand(std::time(NULL));

    tab = new int* [numberOfTables+1];
    for(int a = 0; a < numberOfTables+1; a++){
        tab[a] = new int[size];

        for(int b = 0; b < size; b++){
            if(a == numberOfTables) tab[a][b] = 0;
            tab[a][b] = std::rand() % 11;
        }
    }

    threadVect = new std::thread [threadSize];
}

Sum_table::~Sum_table() {
    for(int a = 0; a < number_of_tables+1; a++) delete tab[a];
    delete[] tab;
    delete[] threadVect;
}

void Sum_table::start() {
    auto start = std::chrono::system_clock::now();
    int start2 = 0;
    int threadSpread = size / thread_size;
    int end2 = start2 + threadSpread;
    for(int a = 0; a < thread_size; a++) {
        //threadVect.emplace_back(&Eratosthenes_sieve::first_numbers,0);
        if(a+1 == thread_size){
            threadVect[a] = std::thread(&Sum_table::add, this, start2, size);
        } else{
            threadVect[a] = std::thread(&Sum_table::add, this, start2, end2);

        }
        start2 = end2;
        end2 += threadSpread;
    }

    for(int a = 0; a < thread_size; a++){
        threadVect[a].join();
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    time1 = elapsed_seconds.count();
}

void Sum_table::print() {
    std::cout << "Tablicy do sumowania" << std::endl;
    for(int a = 0; a < number_of_tables; a++){
        std::cout << "Tablica nr. " << a+1 << " :";
        for(int b = 0; b < size; b++){
            std::cout << " " << tab[a][b];
        }

        std::cout << "." << std::endl;
    }
}

void Sum_table::print_result() {
    std::cout << "Wynik:";
    for(int a = 0; a < size; a++){
        std::cout << " " << tab[number_of_tables][a];
    }

    std::cout << std::endl;
    std::cout << "Time: " << time1 << std::endl;
}

void Sum_table::add(int start, int end) {
    for(int a = start; a < end; a++){
        int wynik = 0;
        for(int b = 0; b < number_of_tables; b++){
            wynik += tab[b][a];
        }

        //vectLock.lock();
        tab[number_of_tables][a] = wynik;
        //vectLock.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

double Sum_table::time() {
    return time1;
}