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
    list.insertAt(2,5);
    list.printList();
    list.deleteAt(2);
    list.printList();
    list.insertAt(4,2);
    list.printList();
    cout<<list.getSize()<<endl;
    list.deleteAt(4);
    list.printList();
    cout<<list.getSize()<<endl;
    list.replaceAt(2,10);
    list.printList();
    list.clear();
    list.printList();


}
