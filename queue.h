// Author: Ahmed yehia
#ifndef DS_ASSIGN2_QUEUE_H
#define DS_ASSIGN2_QUEUE_H

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
    node*prev;
    node(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};
template <class T>
class Queue {
private:
    node *head;
    node *tail;
    int size;
public:
    Queue(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void enqueue(T data);
    T dequeue();
    T first();
    bool isEmpty();
    int getSize();
    void clear();

    void print();


};



#endif //DS_ASSIGN2_QUEUE_H
