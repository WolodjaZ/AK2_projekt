//
// Created by vladimir on 05.05.19.
//

#ifndef C___THREADS_MY_LIST2_H
#define C___THREADS_MY_LIST2_H


#include <clocale>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <chrono>


class My_list2 {
public:
    struct Node{
        int data;
        Node *prev, *next;
    };

private:
    int length;
    Node* head;
    Node* tail;

public:

    My_list2();
    ~My_list2();

    int getLength();

    void push_front(int data);
    Node* pop_front();

    void push_tail(int data);
    Node* pop_tail();

    bool find_by_value(int data);
    Node* find(int index);
    void add(int index, int data);
    void remove_by_value(int data);
    void remove(int index);

    void print();

    void create_random(int size, int minimum, int maximum);

    void create_from_a_file(std::string name);

};


#endif //C___THREADS_MY_LIST2_H
