#include "circularDoublyLinkedList.cpp"
#include "queue.cpp"
#include "stack.cpp"
#include "Double-Linked-List.cpp"
using namespace std;

int main(){
    DoubleLinked<int> list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.insertAtHead(4);
    list.forwardTraversal();
    list.backWordTraversal();
    list.removeAtHead();
    list.forwardTraversal();
    list.swap(0,1);
    list.forwardTraversal();
    }
