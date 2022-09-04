#include<iostream>
using namespace std;

#define n 100

class stack{

    private:
        int arr[n];
        int top;
    public :
        void push(char ch);
        int pop();
        int peek();
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

int stack::pop(){
    if(isEmpty()){
        cout<<"stack is Empty"<<endl;
        return  -1;
    }
    return arr[top--];
    
}

int stack::peek(){
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

int convert(int num,int b){
    stack s;
    int ans=0;
    while(num>0){
        s.push(num%b);
        num=num/b;
    }
    while(!s.isEmpty()){
        ans=ans*10+s.pop();
    }
    return ans;
}

int main(){

    int num,b;
    cout<<"enter the decimal number"<<endl;
    cin>>num;
    cout<<"enter the base of the number system where you want to convert the number"<<endl;
    cin>>b;

    cout<<convert(num,b);
    return 0;
}