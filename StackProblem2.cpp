#include<bits/stdc++.h>
#include "Stack.cpp"
void Longest_Valid_Parentheses(string str){
    Stack<int> StackY;
    int answer=0;
    StackY.push(-1);
    for(int i=0;i<str.size();i++){
        if(StackY.Top() != -1 && str[StackY.Top()] == '(' && str[i] == ')') {
            StackY.pop();
            answer = max(answer, i - StackY.Top());
        }
        else {
            StackY.push(i);
        }
    }
    printf("%d\n",answer);
}

int main(){
    Longest_Valid_Parentheses("");
    Longest_Valid_Parentheses(")()()(");
}