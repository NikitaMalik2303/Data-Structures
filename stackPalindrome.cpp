#include <iostream>
#include<string.h>
using namespace std;

#define n 100

class stack{

    private:
        char arr[n];
        int top;
    public :
        void push(char ch);
        char pop();
        char peek();
        void display();
        bool isEmpty();
        bool isFull();
        stack();
};

stack::stack(){
    top= -1;
}

bool stack::isEmpty(){
    return (top==-1);
}

bool stack::isFull(){
    return (top==n-1);
}

void stack::push(char ch){
    if(isFull()){
        cout<<"stack overflow"<<endl;
        return ;
    }
    arr[++top]=ch;
}

char stack::pop(){
    if(isEmpty()){
        cout<<"stack is Empty"<<endl;
        return  -1;
    }
    return arr[top--];
    
}

char stack::peek(){
    if(isEmpty()){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return arr[top];
}

void stack::display(){
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse(string str){
    stack s;
    string rev="";
    int flag =1;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    while(!s.isEmpty()){
        rev+=s.peek();
        s.pop();
    }
    if(rev==str){
        cout<<"the given string is a palindrome"<<endl;
    }
    else{
        cout<<"the given string is not a palindrome"<<endl;
    }
}

int main(){
    
    
    string str;
    cout<<"enter the string"<<endl;
    cin>>str;
    reverse(str);
    

    return 0;
}