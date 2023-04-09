
#include <iostream>
#include "circularDoublyLinkedList.cpp"
using namespace std;

int main(){
    circularDoublyLinkedList<int> list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.swap(0,3);
    list.printList();
    cout<<list.retrieveAt(0)<<endl;
    list.swap(0,3);
    list.printList();
    list.replaceAt(0,5);
    list.printList();
}
