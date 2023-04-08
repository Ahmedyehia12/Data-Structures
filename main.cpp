#include <bits/stdc++.h>
using namespace std;

//node class
template<typename T>
class node{
public:
    node * nextPtr = NULL;
    T data;
};

// stack implementation
template<typename T>
class Stack{
private:
    node<T> *head = nullptr;
    int Size=0;
public:
    // push == push_front in the linked list

    void push(T value){
        node<T>* new_node = new node<T>;
        new_node->data = value;
        if(head == nullptr){
            head = new_node;
        }else{
            new_node->nextPtr = head;
            head = new_node;
        }
        Size++;
    }

    //pop == pop_front in the linked list
    T pop(){
        if(isEmpty()){
            cout<<"Nothing to pop\n";
            exit(1);
        }
        else {
            T old_value = head->data;
            node<T> *tmp = head;
            head = head->nextPtr;
            delete tmp;
            Size--;
            return old_value;
        }
    }

    T Top(){
        if(!isEmpty()) {
            return (head->data);
        }
        exit(1);
    }

    int size(){
        return Size;
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }

    void clear(){
        node<T> * current = head;
        node<T> * next;
        while (current != nullptr){
            next = current->nextPtr;
            delete current;
            current = next;
        }
        head = nullptr;
        Size=0;
    }

    void print(){
        if(!isEmpty()){
            node<T> *current;
            current = head;
            while(current != nullptr){
                cout<<current->data<<" ";
                current = current->nextPtr;
            }
        cout<<"\n";
        }
    }
};

int main() {
    Stack <char> x;
    x.push('a'); x.push('k'); x.push('c');
    x.print();
    cout<<x.pop()<<"\n";
    cout<<x.Top()<<" "<<x.size()<<" "<<x.isEmpty()<<"\n";
    x.clear();
    cout<<x.size();
    return 0;
}
