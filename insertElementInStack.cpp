#include <iostream>
#include <stack>
using namespace std;

class insert{
    int elem,pos;
    stack<int> b;
    public:
    insert(stack<int> &s,int elem,int pos){
        this->elem = elem;
        this->pos = pos;
        for(int i=s.size();i>=pos;i--){
            b.push(s.top());
            s.pop();
        }
        s.push(elem);
        while(!b.empty()){
            s.push(b.top());
            b.pop();
        }
    }


};

int main(){

    int elem,pos;
    cout<<"enter the element and the position at which you want to insert the element"<<endl;
    cin>>elem>>pos;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    insert(s,elem,pos);

    cout<<s.size()<<endl;
    cout<<s.top()<<endl;

    return 0;
}