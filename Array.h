
#ifndef DS_ASSIGN2_Array_H
#define DS_ASSIGN2_Array_H


#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Array {
private:
    T *arr;
    int max_size;
    int length;
public:
    Array(int n);
    void insert(int element) ;
    void insertAt(int element, int index);
    T retrieveAt(int index) ;
    void removeAt(int index);
    void  replaceAt (T newElement, int index);
    bool isItemAtEqual (T element, int index);
    bool isEmpty () ;
    bool isFull() ;
    int listSize ();
    int  maxListSize ();
    void  clear ();
    void print ();
};

#endif
