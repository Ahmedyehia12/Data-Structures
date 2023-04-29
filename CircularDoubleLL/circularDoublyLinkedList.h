#ifndef DS_ASSIGN2_CIRCULARDOUBLYLINKEDLIST_H
#define DS_ASSIGN2_CIRCULARDOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

///@Author: Ahmed Yehia
template <class T>
struct node {
    T data;
    node *next;
    node *prev;
    node(){
        next = nullptr;
        prev = nullptr;
    }
};
template <class T>
class circularDoublyLinkedList {
private:
    node<T> *head;
    node<T> *tail;
    int size;
public:
    circularDoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    int getSize(){
        return size;
    }
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(int index , T element);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAt(int index);
    T retrieveAt( int index);
    void replaceAt(int index, T element);
    bool isExist(T element);
    bool isItemAtEqual(int index, T element);
    void swap(int index1, int index2);
    bool isEmpty();
    void clear();
    node<T>* getNode(int index);

    void printList(){
        node<T> *temp = head;
        bool start = true;
        while(temp!=head || start){
            cout<<temp->data<<" ";
            temp = temp->next;
            start = false;
        }
        cout<<endl;
    }


};




#endif //DS_ASSIGN2_CIRCULARDOUBLYLINKEDLIST_H
