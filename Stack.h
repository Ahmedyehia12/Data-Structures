//
// Created by 20100 on 4/14/2023.
//

#ifndef DS_ASSIGN2_STACK_H
#define DS_ASSIGN2_STACK_H

#include <bits/stdc++.h>
using namespace std;
template<typename T>
class nodee{
public:
    nodee * nextPtr = NULL;
    T data;
};


template<typename T>
class Stack{
private:
    nodee<T> *head = NULL;
    int Size=0;
public:
    void push(T value);
    T pop();
    T Top();
    int size();
    bool isEmpty();
    void clear();
    void print();
};


#endif //DS_ASSIGN2_STACK_H
