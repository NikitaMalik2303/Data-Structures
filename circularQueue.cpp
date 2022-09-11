#include <iostream>
using namespace std;

#define n 8

class queue{

    int front,rear,N;
    int arr[n];
    public:
    queue(){
        front = -1;
        rear = -1;
    }
    bool isFull(){
        if((rear-front+n)%n==n-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool isEmpty(){
        if(front == rear){
            return 1;
        }
        else{
            return 0;
        }
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear=(rear+1)%n-1;
        arr[rear]=x;
        N++;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        N--;
        front=(front+1)%n;
        return (arr[front]);
    }
    int top(){
        if(isEmpty()){
            cout<<"The queue is empty"<<endl;
            return -1;
        }
        return arr[rear];
    }
    int size(){
        return N;
    }
    void print(){
        for(int i =front+1;i<=rear;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

};

int main(){

    queue a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);
    a.enqueue(6);
    a.enqueue(7);
    a.enqueue(8);
    cout<<a.top()<<endl;
  

    a.print();
    cout<<a.dequeue()<<endl;;
    cout<<a.dequeue()<<endl;
    cout<<a.dequeue()<<endl;
    a.print();
    
    cout<<a.top()<<endl;
    a.enqueue(8);
    a.enqueue(9);
    a.enqueue(10);
    a.print();
    a.enqueue(11);
    a.enqueue(12);
    a.print();

    // a.dequeue();
    // a.dequeue();
    // a.dequeue();
    // a.dequeue();
    // a.dequeue();
    // a.dequeue();
    // a.dequeue();
    // a.dequeue();
    // a.dequeue();
    // a.print();

    return 0;
    
}