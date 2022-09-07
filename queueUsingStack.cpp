#include <iostream>
#include <stack>
using namespace std;

#define n 20

class queue{
    stack<int> a;
    stack<int> b;
    public:
        void push(int x);
        int pop();
        bool empty();
};

void queue::push(int x){
    
    a.push(x);
}

bool queue::empty(){
    if(a.empty()&& b.empty())
        return true;
    return false;
}

int queue::pop(){
    if(a.empty() && b.empty()){
        cout<<"queue is empty"<<endl;
        return -1;
    }
    else{
        if(b.empty()){
            while(!a.empty()){
                int elem = a.top();
                a.pop();
                b.push(elem);
            }
        }
        int val = b.top();
        b.pop();
        return val;
    }
}

int main(){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    

    return 0;
}