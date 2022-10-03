#include <iostream>
using namespace std;

#define n 10

class stack{
    int top;
    int *arr;
    public:
    stack(){
        top=-1;
        arr = new int[n];
    }
    bool isEmpty(){
        return (top==-1);
    }
    bool isFull(){
        return (top==n-1);
    }
    void push(int x){
        if(isFull()){
            cout<<"stack is full"<<endl;
            return ;
        }
        arr[++top]=x;
    }
    int pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

};

void postfixEval(string str){
    stack s;
    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            s.push(str[i]-'0');
        }
        else {
            int op2 = s.pop();
            int op1 = s.pop();
            switch (str[i]){
            case '*':
                s.push(op1 *op2);
                break;
            case '/':
                s.push(op1/op2);
                break;
            case '+':
                s.push(op1+op2);
                break;
            case '-':
                s.push(op1-op2);
                break;
            case '^':
                s.push(op1^op2);
                break;       
            default:
                break;
            }
        }    
    }

    cout<<s.pop()<<endl;
}

int main(){

    string str;
    cout<<"enter the string"<<endl;
    cin>>str;
    postfixEval(str);
    return 0;
}