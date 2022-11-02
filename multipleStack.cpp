#include <iostream>
using namespace std;


class multipleStack{

    int n,k;
    int *arr;
    int *top;
    public:
    multipleStack(int n,int s);
    bool isFull(int s);
    bool isEmpty(int s);
    void push(int x,int s);
    int pop(int s);

};

multipleStack::multipleStack(int n,int k){
    this->n = n;
    this->k = k;
    arr = new int[n];
    top = new int[k];

    for(int i=0;i<k;i++){
        top[i]=(i*n/k)-1;
    }

}

bool multipleStack::isFull(int s){
    if(top[s-1]>=(s*n/k)-1){
        return true;
    }
    else{
        return false;
    }
}

bool multipleStack::isEmpty(int s){
    if(top[s-1]<((s-1)*n/k)){
        return true;
    }
    else{
        return false;
    }
}

void multipleStack::push(int x,int s){
    if(isFull(s)){
        cout<<"stack is full"<<endl;
        return;
    }
    int index = ++top[s-1];
    arr[index]=x;

}

int multipleStack::pop(int s){
    if(isEmpty(s)){
        cout<<"stack is Empty"<<endl;
        return -1;
    }
    int elem = arr[top[s-1]];
    top[s-1]--;
    return elem;
}

int main(){

    
    multipleStack s(6,3);
    s.push(1,1);
    s.push(2,1);
    s.push(3,1);
    s.pop(1);
    s.pop(1);
    s.pop(1);
    s.push(3,2);
    s.push(3,2);
    s.push(3,2);
    s.pop(2);
    s.pop(2);
    s.pop(2);


    return 0;
}