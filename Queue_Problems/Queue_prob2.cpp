#include <iostream>
#include "DS_Assign2/Queue/queue.cpp"
// Author : Ahmed Yehia
using namespace std;

template <class T>
class Qstack{
private:
    Queue<T> q1;
    Queue<T> q2;
public:
    void push(T data){
        q1.enqueue(data);
    }
    T pop(){
        if(q1.isEmpty())
            throw runtime_error("Stack is empty");
        while(q1.getSize() > 1){
            q2.enqueue(q1.dequeue());
        }
        T data = q1.dequeue();
        while(!q2.isEmpty()){
            q1.enqueue(q2.dequeue());
        }
        return data;
    }
    bool isEmpty(){
        return q1.isEmpty();
    }
    int getSize(){
        return q1.getSize();
    }
    void clear(){
        q1.clear();
    }
    void print(){
        q1.print();
    }
};


int main(){
    Qstack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    cout<<s.pop()<<endl;
    s.print();

}

