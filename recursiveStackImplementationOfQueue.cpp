#include <iostream>
#include <stack>
using namespace std;

class queue{

    stack<int> a;
    int front;
    int rear;
    public:
    void push(int x);
    int pop();

};

void queue::push(int x){
    a.push(x);
}

int queue::pop(){
    if(a.empty()){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    int x = a.top();
    a.pop();
    if(a.empty()){
        return x;
    }
    int item = pop();
    a.push(x);
    return item;

}


int main(){



    return 0;
}