#include <iostream>
#include <queue>
using namespace std;

class stack{

    queue<int> a;
    queue<int> b;
    int n;
    public:
    stack();
    void push(int x);
    int pop();
    int size();
    int top();

};

stack::stack(){
    n=0;
}

int stack::pop(){
    if(a.empty()){
        cout<<"stack is empty"<<endl;
        return -1 ;
    }
    int elem = a.front();
    a.pop();
    n--;
    return elem;
}

void stack::push(int x){
    
    b.push(x);
    n++;
    while(!a.empty()){
        b.push(a.front());
        a.pop();
    }

    queue<int> temp = a;
    a=b;
    b=temp;
}

int stack::size(){
    return n;
}

int stack::top(){
    if(a.empty()){
        cout<<"empty stack"<<endl;
        return -1;
    }
    return a.front();
}



int main(){

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.size()<<endl;
    cout<<s.pop()<<endl;  
    cout<<s.pop()<<endl;  
    cout<<s.pop()<<endl;  
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;  
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;  
    cout<<s.pop()<<endl;  

    return 0;
}