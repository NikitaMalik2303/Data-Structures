#include <iostream>
using namespace std;

class stack{
    int *arr;
    int top;
    int n;
    public:
    stack(int n){
        top=-1;
        this->n = n;
        arr = new int[n];
    }
    bool isFull(){
        return(top==n-1);
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(int x){
        if(isFull()){
            cout<<"the array is full"<<endl;
            return;
        }
        arr[++top]=x;
    }
    int pop(){
        if(isEmpty()){
            cout<<"empty stack"<<endl;
            return -1;
        }
        return arr[top--];
    }
    int middle(){
        stack s(n);
        while(top!=n/2){
            s.push(pop());
        }
        int elem = arr[top];
        while(s.isEmpty()){
            push(s.pop());
        }
        return elem;
    }
};

int main(){

    stack a(9);
    for(int i=0;i<9;i++){
        a.push(i);
    }
    cout<<a.middle();
    return 0;
}