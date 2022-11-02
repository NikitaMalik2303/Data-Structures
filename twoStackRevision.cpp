#include <iostream>
using namespace std;

class Stack{

    int top1,top2,n;
    int *arr;
    public:
    Stack(int n){
        arr = new int[n];
        top1=-1;
        top2 =n;
        this->n =n;
    }
    bool isEmpty(){
        return (top1==-1 || top2==n);
    }
    bool isFull(){
        if(top1<top2-1){
            return false;
        }
        else{
            return true;
        }
    }
    void push1(int x){
        if(isFull()){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top1]=x;
    }
    void push2(int x){
        if(isFull()){
            cout<<"Stack overflow"<<endl;
            return ;
        }
        arr[--top2]=x;
    }
    int pop1(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top1--];
    }
    int pop2(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top2++];
    }
    int peek1(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top1];
    }
    int peek2(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top2];
    }
    void display(){
        for(int i=top1;i>=0;i--){
            cout<<arr[i]<<"\t";
        }
        for(int i=top2;i<n;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

};

int main(){

    Stack s(10);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push1(4);
    s.push1(5);
    s.push2(6);
    s.push2(7);
    s.push2(8);
    s.push2(9);
    s.display();

    return 0;
}