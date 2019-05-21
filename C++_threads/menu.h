//
// Created by vladimir on 06.05.19.
//

#ifndef C___THREADS_MENU_H
#define C___THREADS_MENU_H

#include <iostream>
#include <fstream>

#include "Sum_table.h"
#include "Eratosthenes_sieve.h"
#include "Matrix.h"
#include "Sume.h"

class menu {
public:
    menu();
    ~menu();
    void sume_tables();
    void sume();
    void first_numbers();
    void sume_matrix();
};


#endif //C___THREADS_MENU_H
