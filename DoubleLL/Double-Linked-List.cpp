
#include "Double-Linked-List.h"

template <typename T>
void DoubleLinked<T>::insertAtHead(T value) {
    Dl_Node<T>* newOne = new Dl_Node<T>;
    newOne->data = value;
    if (head == nullptr) {
        head = newOne;
        tail = newOne;
    } else {
        newOne->nextPtr = head;
        head->prevPtr = newOne;
        head = newOne;
    }
    Size++;
}

template <typename T>
void DoubleLinked<T>::insertAtTail(T value) {
    Dl_Node<T>* newOne = new Dl_Node<T>;
    newOne->data = value;
    if (head == nullptr) {
        head = newOne;
        tail = newOne;
    } else {
        newOne->prevPtr = tail;
        tail->nextPtr = newOne;
        newOne->nextPtr = nullptr;
        tail = newOne;
    }
    Size++;
}

template <typename T>
void DoubleLinked<T>::insertAfter(Dl_Node<T>* curr, T value) {
    Dl_Node<T>* newOne = new Dl_Node<T>;
    newOne->data = value;
    newOne->nextPtr = curr->nextPtr;
    newOne->prevPtr = curr;

    if (curr->nextPtr != nullptr) {
        curr->nextPtr->prevPtr = newOne;
    }
    curr->nextPtr = newOne;
    Size++;
}

template <typename T>
void DoubleLinked<T>::insertAt(T value, int index) {
    if (index < 0 || index > Size) {
        cout << "Out of range\n";
        return;
    }

    if (index == 0) {
        insertAtHead(value);
        return;
    }

    if (index == Size) {
        insertAtTail(value);
        return;
    }

    Dl_Node<T>* newOne = new Dl_Node<T>(value);
    Dl_Node<T>* tmp = head;
    int x = 0;
    while (x != index && tmp != nullptr) {
        tmp = tmp->nextPtr;
        x++;
    }
    newOne->nextPtr = tmp;
    newOne->prevPtr = tmp->prevPtr;
    tmp->prevPtr->nextPtr = newOne;
    tmp->prevPtr = newOne;
    Size++;

}

template <typename T>
void DoubleLinked<T>::removeAtHead() {
    if(isEmpty()){
        cout<<"The List is Empty!!\n";
    }else{
        Dl_Node<T> *curr = head;
        if (Size != 1){
            head = head->nextPtr;
            head->prevPtr = NULL;
            delete curr;
        }else{
            head = NULL;
            tail = NULL;
            delete curr;
        }
        Size--;
    }
}

template <typename T>
void DoubleLinked<T>::removeAtTail() {
    if(isEmpty()){
        cout<<"The List is Empty!!\n";
    }else{
        Dl_Node<T> *curr = tail;
        if (Size != 1){
            tail = curr->prevPtr;
            tail->nextPtr = NULL;
            delete curr;
        }else{
            head = NULL;
            tail = NULL;
            delete curr;
        }
        Size--;
    }
}

template <typename T>
void DoubleLinked<T>::removeAt(int index) {
    if (isEmpty()) {
        cout << "The List is Empty!!\n";
    }else if (index == 0) {
        removeAtHead();
    } else if (index == Size-1) {
        removeAtTail();
    }else {
        Dl_Node<T> *curr = head;
        for(int i=0;i<index;i++){
            curr = curr->nextPtr;
        }
        curr->prevPtr->nextPtr = curr->nextPtr;
        curr->nextPtr->prevPtr = curr->prevPtr;
        delete curr;
        Size--;
    }
}

template <typename T>
void DoubleLinked<T>::replaceAt(T value, int index) {
    Dl_Node<T> *curr = head;
    if(index<0 || index >Size){
        cout<<"This Index is Empty !!\n";
        exit(1);
    }else{
        for(int i=0;i<index;i++) {
            curr = curr->nextPtr;
        }
    }
    curr->data = value;
}

template <typename T>
T DoubleLinked<T>::retrieveAt(int index) {
    Dl_Node<T> *curr = head;
    if(index<0 || index >Size){
        cout<<"This Index is Empty !!\n";
        exit(1);
    }else{
        for(int i=0;i<index;i++) {
            curr = curr->nextPtr;
        }
    }
    return curr->data;
}

template<class T>
void DoubleLinked<T>::swap(int firstIndex, int secondIndex) {
    if (firstIndex < 0 || firstIndex >= Size || secondIndex < 0 || secondIndex >= Size) {
        cout << "Out of Range!!" << endl;
       
    } else if (firstIndex - secondIndex == 0) {
        cout << "There is No need to swap\n" << endl;
    }else{
    Dl_Node<T>* node1 = head;
    Dl_Node<T>* node2 = head;

    for(int i = 0; i < firstIndex; i++){
        node1 = node1->nextPtr;
    }
    for(int j = 0; j < secondIndex; j++){
        node2 = node2->nextPtr;
    }
        
        
    if (node1 == head) {
        head = node2;
    } else if (node2 == head) {
        head = node1;
    }
    if (node1 == tail) {
        tail = node2;
    } else if (node2 == tail) {
        tail = node1;
    }


    if (node1->prevPtr) {
        node1->prevPtr->nextPtr = node2;
    }
    if (node2->prevPtr) {
        node2->prevPtr->nextPtr = node1;
    }
    if (node1->nextPtr) {
        node1->nextPtr->prevPtr = node2;
    }
    if (node2->nextPtr) {
        node2->nextPtr->prevPtr = node1;
    }


    Dl_Node<T>* temp = node1->prevPtr;
    node1->prevPtr = node2->prevPtr;
    node2->prevPtr = temp;
    temp = node1->nextPtr;
    node1->nextPtr = node2->nextPtr;
    node2->nextPtr = temp;

}
}



template <typename T>
bool DoubleLinked<T>::isEmpty() const {
    if (Size == 0) {
        return true;
    } else {
        return false;
    }
}
template <typename T>
bool DoubleLinked<T>::isExist(T value) const {
    Dl_Node<T> *curr = head;
    while (curr != NULL) {
        if(curr->data == value){
            return true;
        }
        curr = curr->nextPtr;
    }
    return false;
}

template <typename T>
bool DoubleLinked<T>::isItemAtEqual(T value, int index) const {
    Dl_Node<T> *curr = head;
    if(index<0 || index >Size){
        cout<<"Out of Range !!\n";
    }else{
        for(int i=0;i<index;i++) {
            curr = curr->nextPtr;
        }
    }
    return (curr->data == value);
}

template <typename T>
void DoubleLinked<T>::reverse() {
    if(Size >=2){
        Dl_Node<T>* current = head;
        Dl_Node<T>* temp;
        while (current != nullptr) {
            temp = current->prevPtr;
            current->prevPtr = current->nextPtr;
            current->nextPtr = temp;
            current = current->prevPtr;
        }
        temp = head;
        head = tail;
        tail = temp;
    }else if(isEmpty()){
        cout<<"Empty List!!\n";
    }
}

template <typename T>
int DoubleLinked<T>::doubleLinkedListSize () const {
    return Size;
}

template <typename T>
void DoubleLinked<T>::clear(){
    Dl_Node<T>* current = head;
    Dl_Node<T>* next;
    while (current != nullptr) {
        next = current->nextPtr;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    Size = 0;
}

template <typename T>
void DoubleLinked<T>::forwardTraversal() {
    Dl_Node<T> *curr = head;
    if (head == NULL) {
        cout<<"\nEMPTY LIST !!\n";
    } else {
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->nextPtr;
        }
    }
    cout<<"\n";
}

template <typename T>
void DoubleLinked<T>::backWordTraversal() {
    Dl_Node<T> * curr = tail;
    if (tail == NULL) {
        cout<<"\nEMPTY LIST !!\n";
    }else{
        while ( curr!= NULL) {
            cout << curr->data << " ";
            curr = curr->prevPtr;
        }}
    cout<<"\n";
}



