//Author: Hoda Samir

#ifndef DOUBLELINKED_DOUBLE_LINKED_LIST_H
#define DOUBLELINKED_DOUBLE_LINKED_LIST_H
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Dl_Node {
public:
    T data;
    Dl_Node* nextPtr;
    Dl_Node* prevPtr;

    Dl_Node() {
        nextPtr = nullptr;
        prevPtr = nullptr;
    }

    Dl_Node(T x) {
        data = x;
    }
};

template <typename T>
class DoubleLinked {
public:
    Dl_Node<T>* head = nullptr;
    Dl_Node<T>* tail = nullptr;
    int Size = 0;

    // Push Functions
    void insertAtHead(T value);
    void insertAtTail(T value);
    void insertAfter(Dl_Node<T>* curr, T value);
    void insertAt(T value, int index);

    // Pop [ remove ] functions
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);

    // Other functions
    T retrieveAt(int index);
    void replaceAt(T value, int index);
    void reverse();
    void swap(int firstIndex, int secondIndex);
    bool isEmpty() const;
    bool isExist(T value) const;
    bool isItemAtEqual( T value , int index) const;
    int doubleLinkedListSize () const;
    void clear();

    //print functions
    void forwardTraversal();
    void backWordTraversal();
};




#endif //DOUBLELINKED_DOUBLE_LINKED_LIST_H
