#include <iostream>
using namespace std;

class twoQueue{

    int front1,rear1;
    int front2,rear2;
    int n;
    int *arr;

    public:
    twoQueue(int n){
        this->n=n;
        front1=rear1=-1;
        front2=rear2=n;
        arr = new int[n];
    }
    bool isEmpty(){
        if(front1==rear1 || front2==rear2){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(rear1<rear2-1){
            return false;
        }
        return true;
    }
    void push1(int x){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[++rear1]=x;
    }
    void push2(int x){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[--rear2]=x;
    }
    int pop1(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[++front1];
    }
    int pop2(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[--front2];
    }

};

int main(){

    twoQueue a(8);
    a.push1(1);
    a.push1(2);
    a.push1(3);
    a.push1(4);
    a.push2(1);
    a.push2(2);
    a.push2(3);
    a.push2(4);
    cout<<a.pop1()<<endl;
    cout<<a.pop2()<<endl;


    return 0;
}