#include "queue.cpp"

int main(){
    Queue<int>q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print();
    q.clear();
    q.enqueue(5);
    q.enqueue(6);
    q.print();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}
