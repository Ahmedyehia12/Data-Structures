#include "DS_Assign2/SingleLL/linkedList.cpp"
#include <bits/stdc++.h>
template<typename T>
LinkedList <T> mergeKlists(vector<LinkedList<T> >lists) {
    priority_queue<T,vector<T>,greater<T>> pq;
    for(int i=0;i<lists.size();i++){
        if(lists[i].head!=NULL){
            pq.push(lists[i].head->data);
        }
    }
    LinkedList<T>ans;
    while(!pq.empty()){
        T min_element=pq.top();
        pq.pop();
        ans.insertAtTail(min_element);
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i].head!=NULL && lists[i].head->data==min_element) {
                lists[i].head=lists[i].head->next;
                if (lists[i].head!=NULL) {
                    pq.push(lists[i].head->data);
                }
                break;
            }
        }
    }
    return ans;
}
int main() {
    // Test case 1
    LinkedList<int> l1, l2, l3;
    l1.insertAtTail(1);
    l1.insertAtTail(4);
    l1.insertAtTail(5);

    l2.insertAtTail(1);
    l2.insertAtTail(3);
    l2.insertAtTail(4);

    l3.insertAtTail(2);
    l3.insertAtTail(6);

    vector<LinkedList<int>> lists = {l1, l2, l3};
    LinkedList<int> merged_list = mergeKlists(lists);
    merged_list.print();

    // Test case 2
    LinkedList<int> l4, l5, l6;
    l4.insertAtTail(1);
    l4.insertAtTail(3);
    l4.insertAtTail(5);
    l4.insertAtTail(7);

    l5.insertAtTail(2);
    l5.insertAtTail(4);
    l5.insertAtTail(6);
    l5.insertAtTail(8);

    l6.insertAtTail(0);
    l6.insertAtTail(9);
    l6.insertAtTail(10);

    vector<LinkedList<int>> lists2 = {l4, l5, l6};
    LinkedList<int> merged_list2 = mergeKlists(lists2);
    merged_list2.print();

    return 0;
}

