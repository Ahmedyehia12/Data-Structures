#include "queue.cpp"
#include "stack.cpp"
#include "DoubleLL/Double-Linked-List.cpp"
#include "CircularDoubleLL/circularDoublyLinkedList.cpp"
#include"SingleLL/linkedList.cpp"
using namespace std;

int main(){
    LinkedList<int> l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.swap(1,3);
    l.print();
    l.swap(1,3);
    l.print();



    }
