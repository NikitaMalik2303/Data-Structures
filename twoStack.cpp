#include <iostream>
using namespace std;

class twoStack{

    int *arr;
    int n,top1,top2;
    public:
    twoStack(int n);
    bool isFull();
    bool isEmpty();
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
    int peek1();
    int peek2();

};

twoStack::twoStack(int n){
    arr = new int[n];
    top1 = -1;
    top2 = n;
}

bool twoStack::isEmpty(){
    if(top1==-1 || top2==n){
        return true;
    }
    return false;
}

bool twoStack::isFull(){
    if(top1<top2-1){
        return false;
    }
    return true;
}

void twoStack::push1(int x){
    if(isFull()){
        cout<<"Stack overflow"<<endl;
        return;
    }
    arr[++top1]=x;
}

void twoStack::push2(int x){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
        return ;
    }
    arr[--top2]=x;
}

int twoStack::pop1(){
    if(isEmpty()){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return(arr[top1--]);
}

int twoStack::peek1(){
    return arr[top1];
}

int twoStack::peek2(){
    return arr[top2];
}

int twoStack::pop2(){
    if(isEmpty()){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return arr[top2++];
}

int main(){

    twoStack s(6);
    s.push1(1);
    s.push1(1);
    s.push2(1);
    s.push2(1);
    s.push2(1);
    s.push1(1);
    s.push1(1);
    s.push1(1);

    return 0;
}