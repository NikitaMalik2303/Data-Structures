#include <iostream>
using namespace std;

class circular{

    int front,rear,n,N=0;
    int *arr;
    public:
    circular(int n){
        this-> n =n;
        arr = new int[n];
        front = rear =-1;
    }
    bool isEmpty(){
        return (front==rear);
    }
    bool isFull(){
        if((n+rear-front)%n==n-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int x){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        rear = (rear+1)%n;
        arr[rear]=x;
        N++;
    }
    int pop(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        front = (front+1)%n;
        N--;
        return arr[front];
    }
    int peek(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    int size(){
        return N;
    }
    void display(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        for(int i=front+1;i%n!=rear;i++){
            cout<<arr[i%n]<<"\t";
        }
        cout<<arr[rear]<<endl;
    }

};

int main(){

    circular a(5);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    a.display();
    a.push(7);
    a.push(8);
    a.display();

    return 0;
}