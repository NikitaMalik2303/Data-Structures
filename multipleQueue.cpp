#include <iostream>
using namespace std;

class multipleQueue{

    int k,n;
    int *arr;
    int *front;
    int *rear;
    public:
    multipleQueue(int n,int k){
        this->n = n;
        this->k =k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        for(int i=0;i<k;i++){
            front[i] = rear[i] = i*n/k-1;
        }
    }
    bool isEmpty(int s){
        if(front[s-1]<=(s-1)*n/k-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(int s){
        if(rear[s-1]<s*n/k-1){
            return false;
        }
        else{
            return true;
        }
    }
    void push(int x,int s){
        if(isFull(s)){
            cout<<"Queue is full"<<endl;
            return ;
        }
        arr[++rear[s-1]]=x;
    }
    int pop(int s){
        if(isEmpty(s)){
            cout<<"queue is empty"<<endl;
            return -1;
        } 
        return arr[++front[s-1]];
    }

};

int main(){

    multipleQueue a(6,3);
    a.push(1,1);
    a.push(2,1);
    a.push(3,1);

    a.push(1,2);
    a.push(1,2);
    a.push(1,2);
    a.push(1,3);
    a.push(1,3);
    a.push(1,3);


    return 0;
}