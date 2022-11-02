#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s,int elem){
    if(s.empty()){
        s.push(elem);
    }
    int topelem = s.top();
    s.pop();
    insertAtBottom(s,elem);
    s.push(topelem);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int elem = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,elem);
}

int main(){
    stack<int> s;
    for(int i=0;i<5;i++){
        cout<<i<<"\t";
        s.push(i);
    }
    cout<<endl;

    while(!s.empty()){
        cout<<s.top()<<"\t";
        s.pop();
    }

    return 0;
}
