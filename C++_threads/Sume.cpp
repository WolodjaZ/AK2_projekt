//
// Created by vladimir on 05.05.19.
//

#include "Sume.h"

Sume::Sume(int size, int threadsSize) : size(size), threads_size(threadsSize) {
    tab = new int [size];
    threadVect = new std::thread [threadsSize];

    srand(std::time(NULL));
    for(int a = 0; a < size; a++){
        tab[a] = std::rand() % 101;
    }
}

Sume::~Sume() {
    delete[] tab;
    delete[] threadVect;
}


void Sume::start() {
    auto start = std::chrono::system_clock::now();
    int max = log10(size)+1;
    int length = 10;
    for(int b = 0; b < max; b++){
        for(int a = 0; a < threads_size; a++) {
            //threadVect.emplace_back(&Eratosthenes_sieve::first_numbers,0);
            threadVect[a] = std::thread(&Sume::add, this, a*length, length);
        }

        for(int a = 0; a < threads_size; a++){
            threadVect[a].join();
        }

        length = length*10;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    time1 = elapsed_seconds.count();
}

void Sume::print() {
    std::cout << "Tablica:";
    for(int a = 0; a < size; a++){
        std::cout << " " << tab[a];
    }
    std::cout << std::endl;
}

void Sume::pirnt_result() {
    std::cout << "Wynik: " << tab[0] << std::endl;
    std::cout << "Time: " << time1*1000 << " in [ms]" << std::endl;
}

double Sume::time() {
    return time1;
}

void Sume::add(int index, int length) {
    if(index >= size)
        return;

    int wynik = 0;
    for(int a = index; a < index+length; ){
        //std::cout << a << std::endl;
        if(a >= size) break;
        wynik += tab[a];
        tab[a] = 0; // jak się tutaj blokuje to wyniki są nie malejące
        a += length/10;
    }

    //vectLock.lock();
    tab[index] = wynik;
    //vectLock.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    add(index + length*threads_size, length);
}
