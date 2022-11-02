#include <iostream>
using namespace std;

class MultipleStack{

    int *top;
    int *arr;
    int n,k;
    public:
    MultipleStack(int n ,int k){
        arr = new int[n];
        top = new int[k];
        for(int i=0;i<k;i++){
            top[i] = (n/k)*i-1;
        }
        this-> n =n;
        this->k =k;
    }
    bool isEmpty(int s){
        if(top[s-1]<(s-1)*n/k-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(int s){
        if(top[s-1]>=s*(n/k)-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int x,int s){
        if(isFull(s)){
            cout<<"Stack is full"<<endl;
            return;
        }
        arr[++top[s-1]]=x;
    }
    int pop(int s){
        if(isEmpty(s)){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top[s-1]--];
    }
    int peek(int s){
        if(isEmpty(s)){
            cout<<"Stack underflow"<<endl;
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
    MultipleStack s(n,k);
    s.push(1,1);
    s.push(2,1);
    s.push(3,1);
    cout<<s.peek(1);

    return 0;
}