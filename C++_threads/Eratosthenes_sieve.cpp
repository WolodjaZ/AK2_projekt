//
// Created by vladimir on 24.04.19.
//

#include "Eratosthenes_sieve.h"

Eratosthenes_sieve::Eratosthenes_sieve(int interval, int thread_size) {
    this->thread_size = thread_size;
    size = interval-2;
    tab = new int [size];
    inUse = new bool [size];
    for(int a = 0; a < size; a++) {
        tab[a] = a+2;
        inUse[a] = false;
    }

}

Eratosthenes_sieve::~Eratosthenes_sieve() {
    delete[] tab;
    threadVect.clear();
    //std::cout << "Siema" <<std::endl;
    //delete[] threadVect;
    //std::cout << "Siema" <<std::endl;
}

void Eratosthenes_sieve::start() {
    auto start = std::chrono::system_clock::now();
    for(int a = 0; a < thread_size; a++) {
        threadVect.emplace_back(&Eratosthenes_sieve::first_numbers, this, a);
        //threadVect[a] = std::thread(&Eratosthenes_sieve::first_numbers, this, 0);

    }
    /*for (auto i = threadVect.begin(); i != threadVect.end(); i++) {
        (*i).join();
    }*/
    for(auto& t: threadVect){t.join();}
    //for(int a = 0; a < thread_size; a++){
    //    threadVect[a].join();
    //}
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    time1 = elapsed_seconds.count();

}

void Eratosthenes_sieve::first_numbers(int index) {
    if(index >= size) return;
    if(tab[index] != 0){
        if(!inUse[index]){
            //vectLock.lock();
            inUse[index] = true;
            //vectLock.unlock();
            int a = index;
            while(a < size){
                if(tab[index] == 0) break;
                if(a != index){
                    tab[a] = 0;
                }
                //std::cout << a << " " << a+2 << " " << tab[a] << std::endl;
                a += (index+2);
            }
        }
    }
    //std::cout << index << " " << index+2 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    first_numbers(index+thread_size);
}

void Eratosthenes_sieve::print() {
    std::cout << "Liczby pierwsze: ";
    for(int a = 2; a < size; a++){
        if(tab[a-2] != 0)
            std::cout << " " <<tab[a-2];
    }
    std::cout << std::endl;

    std::cout << "Time: " << time1*1000 << " in [ms]" << std::endl;
}

double Eratosthenes_sieve::time() {
    return time1;
}

void Eratosthenes_sieve::change(int interval, int thread_size) {
    delete[] tab;
    threadVect.clear();
    this->thread_size = thread_size;
    size = interval-2;
    tab = new int [size];
    inUse = new bool [size];
    for(int a = 0; a < size; a++) {
        tab[a] = a+2;
        inUse[a] = false;
    }
    time1 = 0;

}
