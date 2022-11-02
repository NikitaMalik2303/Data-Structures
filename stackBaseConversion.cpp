#include <iostream>
using namespace std;

#define n 10

class Stack{
    int top;
    int arr[n];
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
    void push(int x){
        if(isFull()){
            cout<<"Stack is full"<<endl;
            return;
        }
        arr[++top]=x;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top];
    }
};

void convert(int num,int b){
    Stack s;
    while(num>0){
        s.push(num%b);
        num=num/b;
    }
    int res =0;
    while(!s.isEmpty()){
        res = res*10+s.pop();
    }
    cout<<res<<endl;
}

int main(){

    int num,b;
    cout<<"Enter the number"<<endl;
    cin>>num;
    cout<<"enter the base of the number"<<endl;
    cin>>b;
    convert(num,b);


    return 0;
}