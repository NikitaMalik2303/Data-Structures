#include <iostream>
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

bool check(string str){
    stack s;
    bool flag = 1;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' ||str[i]=='['){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            if(!s.isEmpty() && s.peek()=='('){
                s.pop();
            }
            else{
                flag = 0;
            }            
        }
        else if(str[i]==']'){
            if(!s.isEmpty() && s.peek()=='['){
                s.pop();
            }
            else{
                flag =0;
            }            
        }
        else if(str[i]=='}'){
            if(!s.isEmpty() && s.peek()=='{'){
                s.pop();
            }
            else{
                flag =0;
            }             
        }

    }
    if(!s.isEmpty()){
        flag =0;
    }
    return flag ;
}

int main(){

    string str;
    cin>>str;
    int ans = check(str);

    if(ans){
        cout<<"the expression is correct"<<endl;
    }
    else{
        cout<<"the expression is not correct"<<endl;
    }

    return 0;
}