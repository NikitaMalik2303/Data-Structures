#include <iostream>
using namespace std;

#define n 10

class Stack{

    int top;
    char arr[n];
    public:
    Stack(){
        top=-1;
    }
    bool isEmpty(){
        return(top==-1);
    }
    bool isFull(){
        return (top==n-1);
    }
    void push(char ch){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top]=ch;
    }
    char pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return '0';
        }
        return arr[top--];
    }
    char peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return '0';
        }
        return arr[top];
    }

};

bool palindrome(string str){

    Stack s;
    for(int i=0;str[i]!='\0';i++){
        s.push(str[i]);
    }
    string rev;
    while(!s.isEmpty()){
        rev +=s.pop();
    }
    return (rev==str);

}

int main(){

    string str;
    cout<<"please enter the string"<<endl;
    cin>>str;
    if(palindrome(str)){
        cout<<"String is a palindrome"<<endl;
    }
    else{
        cout<<"string is not a palindrome"<<endl;
    }

    return 0;
}