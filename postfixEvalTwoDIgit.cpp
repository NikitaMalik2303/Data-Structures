#include <iostream>
#include <ctype.h>
using namespace std;

#define n 100

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
            cout<<"Stack is full"<<endl;
            return;
        }
        arr[++top]==x;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
};



void evaluate(string str){
    stack s;
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            continue;
        }
        else if(isdigit(str[i])!=0){
            int num = 0;
            while(isdigit(str[i])!=0){
                num = num*10 + (int)(str[i]-'0');
                i++;
            }
            i--;
            s.push(num);
        }
        else {
            int op2 = s.pop();
            int op1 = s.pop();
            switch (str[i]){
                case '^':
                    s.push(op1^op2);
                    break;
                case '*':
                    s.push(op1*op2);
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
                default:
                    break;
            }
        }
    }

    cout<<s.pop()<<endl;
}

int main(){

    string str = "100 200 + 2 / 5 * 7 +";
    // cout<<"enter the string to evaluate"<<endl;
    // cin>>str;

    evaluate(str);

    return 0;
}