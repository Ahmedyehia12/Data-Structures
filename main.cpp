#include <iostream>
#include "circularDoublyLinkedList.cpp"
using namespace std;

int main(){
    circularDoublyLinkedList<int> list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.printList();
    list.swap(1,3);
    list.printList();

}
