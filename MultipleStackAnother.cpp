#include <iostream>
using namespace std;

class Stack{
    int n,k;
    int *top;
    int *arr;
    int *boundary;
    public:
    Stack(int n,int k){
        this->n =n;
        this->k =k;
        arr = new int[n];
        top = new int[k];
        boundary = new int[k];
        for(int i=0;i<k;i++){
            top[i]=boundary[i]= i*n/k -1;
        }
    }
    void push(int x,int s){
        if(top[s-1]==boundary[s] || top[s-1]==n-1){
            cout<<"Stack is full"<<endl;
            return;
        }
        arr[++top[s-1]] = x;
    }
    int pop(int s){
        if(top[s-1]==boundary[s-1]){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top[s-1]--];
    }
    int peek(int s){
        if(top[s-1]==boundary[s-1]){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top[s-1]];
    }
};

int main(){

    int n,k;
    cout<<"enter the size of the stack"<<endl;
    cin>>n;
    cout<<"enter the number of stacks"<<endl;
    cin>>k;
    Stack s(n,k);
    s.push(1,1);
    s.push(2,1);
    s.push(3,1);
    cout<<s.peek(1);


    return 0;
}