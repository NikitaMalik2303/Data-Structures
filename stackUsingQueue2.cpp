#include <iostream>
#include <queue>
using namespace std;

class stack{
    queue<int> a;
    queue<int> b;
    int n;
    public:
    void push(int x);
    int pop();
    int top();
    int size();
    stack();
};

stack::stack(){
    n=0;
}

void stack::push(int x){
    a.push(x);
    n++;
}

int stack::pop(){
    if(a.empty()){
        cout<<"empty stack"<<endl;
        return -1;
    }
    while(a.size()!=1){
        int elem = a.front();
        a.pop();
        b.push(elem);
    }
    int elem = a.front();
    a.pop();
    n--;

    queue<int> temp = a;
    a=b;
    b=temp;
    
    return elem;

}

int stack::top(){
    if(a.empty()){
        cout<<"Empty stack"<<endl;
        return -1;
    }
    while(a.size()!=1){
        b.push(a.front());
        a.pop();
    }
    int elem = a.front();
    a.pop();
    b.push(elem);

    queue<int> temp =a;
    a=b;
    b=temp;

    return elem;
}

int stack::size(){
    return n;
}

int main(){

    stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    cout<<a.size()<<endl;
    cout<<a.top()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;

    return 0;
}