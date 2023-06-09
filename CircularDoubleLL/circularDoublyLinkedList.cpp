#include"circularDoublyLinkedList.h"

template<class T>
void circularDoublyLinkedList<T>::insertAtHead(T element) {
    node<T> *new_node = new node<T>;
    new_node->data = element;
    if(head == nullptr){
        head = new_node;
        tail = new_node;
        size++;
        return;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        tail->next = head;
        head->prev = tail;
        this->size++;
        return;
    }
}
template<class T>
void circularDoublyLinkedList<T>::insertAtTail(T element) {
    node<T>* new_node = new node<T>;
    new_node->data = element;
    if(head == nullptr){
        head = new_node;
        tail = head;
        this->size++;
        return;
    }
    else{
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        tail->next = head;
        head->prev = tail;
        this->size++;
        return;
    }
}

template<class T>
void circularDoublyLinkedList<T>::insertAt(int index ,T element) {
    node<T> * new_node = new node<T>;
    new_node->data = element;
    if(index > this->size){
        cout<<"Invalid index"<<endl;
        return;
    }
    else if(index == 0){
        insertAtHead(element);
        return;
    }
    else if(index == this->size){
        insertAtTail(element);
        return;
    }
    else{
        node<T> * temp = head;
        for(int i=0;i<index-1;i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;
        this->size++;
        return;
    }
}
template<class T>
void circularDoublyLinkedList<T>::deleteAtHead() {
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        node<T> * temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete temp;
        this->size--;
        return;
    }
}
template<class T>
void circularDoublyLinkedList<T>::deleteAtTail() {
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        node<T> * temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
        this->size--;
        return;
    }
}
template<class T>
void circularDoublyLinkedList<T>::deleteAt(int index) {
    if(index > this->size){
        cout<<"Invalid index"<<endl;
        return;
    }
    else if(index == 0){
        deleteAtHead();
        return;
    }
    else if(index == this->size){
        deleteAtTail();
        return;
    }
    else{
        node<T> * temp = head;
        for(int i=0;i<index;i++){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        this->size--;
        return;
    }


}
template<class T>
T circularDoublyLinkedList<T>::retrieveAt(int index) {
    if(index > this->size-1){
        cout<<"Invalid index"<<endl;
        return -1;
    }
    else{
        node<T> * temp = head;
        bool start = true;
        for(int i=0;i<index && (temp!=head || start);i++){
            temp = temp->next;
            start = false;
        }
        return temp->data;
    }

}
template<class T>
void circularDoublyLinkedList<T>::replaceAt(int index, T element) {
    if(index > this->size-1){
        cout<<"Invalid index"<<endl;
        return;
    }
    else{
        node<T> * temp = head;
        bool start = true;
        for(int i=0;i<index && (temp!=head || start);i++){
            temp = temp->next;
            start = false;
        }
        temp->data = element;
        return;
    }
}
template<class T>
bool circularDoublyLinkedList<T>::isExist(T element) {
    node<T> * temp = head;
    bool start = true;
    while(temp!=head || start){
        if(temp->data == element){
            return true;
        }
        temp = temp->next;
        start = false;
    }
    return false;
}

template<class T>
bool circularDoublyLinkedList<T>::isItemAtEqual(int index, T element) {
    if(index > this->size-1){
        cout<<"Invalid index"<<endl;
        return false;
    }
    else{
        node<T> * temp = head;
        bool start = true;
        for(int i=0;i<index && (temp!=head || start);i++){
            temp = temp->next;
            start = false;
        }
        if(temp->data == element){
            return true;
        }
        else{
            return false;
        }
    }
}

template<class T>
node<T> *circularDoublyLinkedList<T>::getNode(int index) {
    if (index < 0 || index >= this->size) {
        cout << "Invalid index" << endl;
        return nullptr;
    }

    node<T>* temp = head;
    bool start = true;
    for (int i = 0; i < index && (temp != head || start); i++) {
        temp = temp->next;
        start = false;
    }

    return temp;
}
template<class T>
void circularDoublyLinkedList<T>::swap(int index1, int index2) {
    if (index1 < 0 || index1 >= this->size || index2 < 0 || index2 >= this->size) {
        cout << "Invalid index" << endl;
        return;
    }
    else{
        node<T> * temp1 = getNode(index1);
        node<T> * temp2 = getNode(index2);
        if (temp1 == head){
            head = temp2;
        }
        else if (temp2 == head){
            head = temp1;
        }
        if (temp1 == tail){
            tail = temp2;
        }
        else if (temp2 == tail){
            tail = temp1;
        }

        node<T>* temp;
        temp = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp;

        temp1->next->prev = temp1;
        temp2->next->prev = temp2;

        temp = temp1->prev;
        temp1->prev = temp2->prev;
        temp2->prev = temp;

        temp1->prev->next = temp1;
        temp2->prev->next = temp2;

    }
}




template<class T>
bool circularDoublyLinkedList<T>::isEmpty() {
    return size == 0;
}

template<class T>
void circularDoublyLinkedList<T>::clear() {
    node<T> * temp = head;
    bool start = true;
    while(temp != head|| start ){
        node<T> * temp2 = temp;
        temp = temp->next;
        temp2->prev = nullptr;
        temp2->next = nullptr;
        start = false;
        delete temp2;
    }
    head = nullptr;
    tail = nullptr;
    this->size = 0;


}

