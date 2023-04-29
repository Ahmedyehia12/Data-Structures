//
// Created by 20100 on 4/14/2023.
//

#include "Stack.h"
template<typename T>
int Stack<T>::size() {
    return Size;

}

template<typename T>
void  Stack<T>::push(T value) {
    nodee<T>* new_node = new nodee<T>;
    new_node->data = value;
    if(head == nullptr){
        head = new_node;
    }else{
        new_node->nextPtr = head;
        head = new_node;
    }
    Size++;
}

template<typename T>
void  Stack<T>::print(){
    if(!isEmpty()){
        nodee<T> *current;
        current = head;
        while(current != nullptr){
            cout<<current->data<<" ";
            current = current->nextPtr;
        }
        cout<<"\n";
    }
}
template<typename T>
T Stack<T>::pop() {
    if(isEmpty()){
        return T();
    }
    else {
        T old_value = head->data;
        nodee<T> *tmp = head;
        head = head->nextPtr;
        delete tmp;
        Size--;
        return old_value;
    }

}

template<typename T>
T Stack<T>::Top() {
    if (!isEmpty()) {
        return head->data;
    }
    else {
        return T();
    }
}
template<typename T>
bool Stack<T>::isEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}

template<typename T>
void Stack<T>::clear() {
    nodee<T> * current = head;
    nodee<T> * next;
    while (current != nullptr){
        next = current->nextPtr;
        delete current;
        current = next;
    }
    head = nullptr;
    Size=0;

}
