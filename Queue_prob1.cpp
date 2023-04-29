#include <iostream>
#include "queue.cpp"
using namespace std;
int main(){
    int n;
    cin>>n;
    Queue<string> q;
    q.enqueue("1");
    string binary = "";
    for(int i=0;i<n;i++){
        binary = q.dequeue();
        cout<<binary<<' ';
        q.enqueue(binary+"0");
        q.enqueue(binary+"1");
    }
    cout<<endl;

}