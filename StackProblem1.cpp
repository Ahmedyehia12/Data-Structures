//Author : Hoda Samir
#include<bits/stdc++.h>
#include "Stack.cpp"
void infix_to_postfix(string str){
    Stack<char> StackY;
    string postfix="";
    map<char,int>operators = {{'^',3},{'*',2} , {'/',2} , {'+',1},{'-',1},{'(',0},{')',0}};
    for(int i=0;i<str.size();i++){
        if(operators.find(str[i]) != operators.end()){
            if(str[i] == '('){
                StackY.push(str[i]);
            }
            else if(str[i] == ')'){
                while(StackY.Top() != '('){
                    postfix+=StackY.pop();
                }
                StackY.pop();
            }
            else{
                while(!StackY.isEmpty() && operators.find(str[i])->second <= operators.find(StackY.Top())->second) {
                    postfix+=StackY.pop();
                }
                StackY.push(str[i]);
            }
        }
        else if(isspace(str[i])){
        }
        else{
            postfix+=str[i];
        }
    }

    while (!StackY.isEmpty()){
        postfix+=StackY.pop();
    }
    cout<<postfix<<"\n";
}


int main() {
    infix_to_postfix("(A + B) * (C + D)");
    return 0;
}
