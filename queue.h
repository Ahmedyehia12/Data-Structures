// Author: Ahmed yehia
#ifndef DS_ASSIGN2_QUEUE_H
#define DS_ASSIGN2_QUEUE_H

#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Node {
    T data;
    Node *next;
    Node *prev;
    Node(){
        next = nullptr;
        prev = nullptr;
    }
};
template <class T>
class Queue {
private:
    Node<T> *head;
    Node<T> *tail;
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
