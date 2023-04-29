//Author:Maya Hisham
#include "DS_Assign2/SingleLL/linkedList.cpp"
#include <bits/stdc++.h>
template<typename T>
LinkedList<int> combine_Nodes(LinkedList<int> input_list){
    SLLNode<int> *current=input_list.head;
    int sum=0;
    LinkedList<int> output_list;
    while (current!=NULL){
        sum+=current->data;
        if(current->data==0 && sum!=0){
            output_list.insertAtTail(sum);
            sum=0;
        }
        else if(current->next==NULL){
            output_list.insertAtTail(sum);
        }
        current=current->next;
    }
    return output_list;
}
int main() {

    LinkedList<int> input_list1;
    input_list1.insertAtTail(0);
    input_list1.insertAtTail(3);
    input_list1.insertAtTail(1);
    input_list1.insertAtTail(0);
    input_list1.insertAtTail(4);
    input_list1.insertAtTail(5);
    input_list1.insertAtTail(2);
    input_list1.insertAtTail(0);
    LinkedList<int> output_list1 = combine_Nodes <int>(input_list1);
    output_list1.print();
    LinkedList<int> input_list2;
    input_list2.insertAtTail(0);
    input_list2.insertAtTail(1);
    input_list2.insertAtTail(0);
    input_list2.insertAtTail(3);
    input_list2.insertAtTail(0);
    input_list2.insertAtTail(2);
    input_list2.insertAtTail(2);
    input_list2.insertAtTail(0);
    LinkedList<int> output_list2 = combine_Nodes <int> (input_list2);
    output_list2.print();
    return 0;
}
