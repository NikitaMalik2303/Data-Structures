#include <iostream>
using namespace std;

#define n 100

class queue{

    int *arr;
    int front;
    int rear;
    public:
    queue(){
        arr = new int[n];
        front =-1;
        rear = -1;
    }
    bool isFull();
    bool isEmpty();
    void push(int x);
    int pop();
    void display();

};

bool queue::isFull(){
    return (rear==n-1);
}

bool queue::isEmpty(){
    return(front==rear);
}

void queue::push(int x){

    if(isFull()){
        return;
    }
    arr[++rear]=x;

    if(front==-1){
        front++;
    }

}

int queue::pop(){

    if(isEmpty()){
        return -1;
    }
    return (arr[front++]);

}

void queue::display(){

    if(!isEmpty()){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

};

int main(){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<q.pop()<<endl;
    q.display();
    cout<<q.pop()<<endl;
    q.display();
    q.push(3);
    q.display();

}