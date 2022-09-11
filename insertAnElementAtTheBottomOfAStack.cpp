#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &a ,int n){

    stack<int> b;
    while(!a.empty()){
        b.push(a.top());
        a.pop();
    }
    a.push(n);
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
    return;
}

int main(){

    stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);

    cout<<a.top()<<endl;
    cout<<a.size()<<endl;

    int n;
    cout<<"enter the element"<<endl;
    cin>>n;

    insert(a,n);

    cout<<a.top()<<endl;
    cout<<a.size()<<endl;

    return 0;
}