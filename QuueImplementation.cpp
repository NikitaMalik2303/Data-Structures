#include <iostream>
using namespace std;

class que{

    int front,rear,n;
    int *arr;
    public:
    que(int n){
        this->n =n;
        arr =new int[n];
        front = rear =-1;
    }
    bool isEmpty(){
        return (front == rear);
    }
    bool isFull(){
        return (rear == n-1);
    }
    void push(int x){
        if(isFull()){
            cout<<"queue is full"<<endl;
            return;
        }
        arr[++rear]=x;
    }
    int pop(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[++front];
    }
    int peek(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[rear];
    }
    void display(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        for(int i=front +1;i<=rear;i++){
            cout<<arr[i]<<"\t";
        }
    }
};

int main(){

    que s(8);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    s.display();


    return 0;
}