#include "queue.h"

template<class T>
void Queue<T>::enqueue(T data) {
    node * new_node = new node;
    new_node->data = data;
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    size++;
}

template<class T>
T Queue<T>::dequeue() {
    if(isEmpty())
        throw runtime_error("Queue is empty");
    node* temp = head;
    head = head->next;
    T data = temp->data;
    delete temp;
    size--;
    return data;
}
template<class T>
T Queue<T>::first() {
    if(isEmpty())
        throw runtime_error("Queue is empty");
    return head->data;
}
template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}
template<class T>
int Queue<T>::getSize() {
    return size;
}

template<class T>
void Queue<T>::clear() {
       node* temp = head;
       while (temp != nullptr) {
            node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;

}

template<class T>
void Queue<T>::print() {
    node* temp = head;
    while (temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}







