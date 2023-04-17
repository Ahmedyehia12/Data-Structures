#include "Array.h"
template <typename T>
Array<T>::Array(int n) {
    max_size = n;
    arr = new T[max_size];
    length = 0;
}

template <typename T>
void Array<T>::insert(int element) {
    if (length >= max_size) {
        cout << "ERROR!!!" << endl;
        return;
    } else {
        arr[length++] = element;
    }
}
template <typename T>
void Array<T>::insertAt(int element, int index) {
    if (length >= max_size || index < 0 || index >= length) {
        cout << "Error!!!" << endl;
        return;
    }
    for (int i = length; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    length++;
}
template <typename T>
T Array<T>:: retrieveAt(int index) {
    if (index < 0 || index >= length) {
        cout<< "out of range!!!";
        return 0;
    } else
        return arr[index];
}
template <typename T>
void Array<T>::removeAt(int index){
    for (int i=index;i<length-1;i++){
        arr[i]=arr[i+1];
    }
    length--;
}
template <typename T>
void Array<T>:: replaceAt (T newElement, int index){
    if (index < 0 || index >= length) {
        cout<< "out of range!!!";
        return;
    }
    arr[index]=newElement;
}
template <typename T>
bool Array<T>::isItemAtEqual (T element, int index) {
    if (index < 0 || index >= length) {
        cout<< "out of range!!!";
        return false;
    }
    if (arr[index]==element){
        return true;
    }
    else
        return false;
}
template <typename T>
bool Array<T>:: isEmpty () {
    if(length==0){
        return true;
    }
    else
        return false;
}
template <typename T>
bool Array<T>:: isFull() {
    if(length>=max_size){
        return true;
    }
    else
        return false;
}
template <typename T>
int Array<T>::listSize (){
    return length;

}
template <typename T>
int Array<T>:: maxListSize (){
    return max_size;

}
template <typename T>
void Array<T>:: clear (){
    length=0;

}
template <typename T>
void Array<T>::print (){
    if (isEmpty()) {
        cout << "Empty Array!!!" << endl;
        return;
    }
    for( int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}