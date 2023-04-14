

#ifndef DS_ASSIGN2_LINKEDLIST_H
#define DS_ASSIGN2_LINKEDLIST_H
#include <bits/stdc++.h>

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T element) ;
};

template <class T>
class LinkedList {
public:
    Node<T> *head;
    Node<T> *tail;
    int size;
    LinkedList();
    void insertAtHead(T element) ;
    void insertAtTail(T element) ;
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index) ;
    T retrieveAt(int index) ;
    void replaceAt(T newElement, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap( int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();

};


#endif //DS_ASSIGN2_LINKEDLIST_H
