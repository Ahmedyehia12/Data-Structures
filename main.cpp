#include "Queue/queue.cpp"
#include "Stack/Stack.cpp"
#include "DoubleLL/Double-Linked-List.cpp"
#include "CircularDoubleLL/circularDoublyLinkedList.cpp"
#include"SingleLL/linkedList.cpp"
#include "Array/Array.cpp"
using namespace std;

int main(){
      circularDoublyLinkedList<int> c;
        c.insertAtHead(1);
        c.insertAtHead(2);
        c.insertAtHead(3);
        c.insertAtHead(4);
        c.printList();
        c.clear();
        c.insertAtHead(5);
        c.insertAtHead(6);
        c.printList();
        c.clear();
        c.printList();
}
