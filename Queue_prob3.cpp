#include <iostream>
#include "queue.cpp"
using namespace std;
//Author : Ahmed Yehia
void sortQueue(Queue<int> &q){
 if(q.isEmpty())
    return;
    Queue<int> temp_q;
    while(!q.isEmpty()) {
        int curr_min = q.first();
        int curr_size = q.getSize();
        int i = 0;
        while(i < curr_size) {
            if(q.first() < curr_min) {
                curr_min = q.first();
            }
            q.enqueue(q.first());
            q.dequeue();

            i++;
        }

        i = 0;
        while(i < curr_size) {
            if(q.first() != curr_min) {
                q.enqueue(q.first());
            }
            else {
                temp_q.enqueue(q.first());
            }

            q.dequeue();

            i++;
        }
    }
    while(!temp_q.isEmpty()) {
        q.enqueue(temp_q.first());
        temp_q.dequeue();
    }
}

int main(){
  Queue<int>q;
  q.enqueue(3);
  q.enqueue(15);
  q.enqueue(2);
  q.enqueue(4);
  sortQueue(q);
  q.print();
}
