#include <iostream>
using namespace std;

class cQue{

    int front,rear;
    int n,N;
    int *arr;

    public:
    cQue(int n){
        this->n =n;
        N=0;
        front = rear =-1;
        arr = new int [n];
    }
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        return false;
    }
    bool isFull(){
        if((n+rear-front)%n==n-1){
            return true;
        }
        return false;
    }
    void push(int x){
        if(isFull()){
            cout<<"Queue overflow"<<endl;
            return;
        }
        rear = (rear+1)%n;
        arr[rear]=x;
        N++;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        front = (front +1)%n;
        return arr[front];
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return ;
        }
        for(int i=front +1;i%n!=rear;i++){
            cout<<arr[i%n]<<"\t";
        }
        cout<<arr[rear]<<endl;
    }

};

int main(){

    cQue q(8);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    q.display();

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.display();

    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.push(12);

    q.display();

    return 0;
}