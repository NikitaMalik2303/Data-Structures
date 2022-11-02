#include <iostream>
using namespace std;

#define n 100

class stack{
    int top;
    char *arr;
    public:
    stack(){
        top=-1;
        arr= new char[n];
    }
    bool isEmpty(){
        return (top==-1);
    }
    bool isFull(){
        return (top==n-1);
    }
    char pop(){
        if(isEmpty()){
            cout<<"Stack is EMpty"<<endl;
            return '0';
        }
        return arr[top--];
    }
    void push(char x){
        if(isFull()){
            cout<<"stack is full"<<endl;
            return;
        }
        arr[++top]=x;
    }
    char peek(){
        if(isEmpty()){
            return '0';
        }
        return arr[top];
    }
};

int prec(char op){
    if(op=='^'){
        return 3;
    }
    else if(op=='*' || op=='/'){
        return 2;
    }
    else if(op=='+' || op=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
 
void convert(string str){
    stack s;
    string res ="";
    for(int i=0;i<str.length();i++){
        char cc = str[i];
        if(cc>='a' && cc<='z' || cc>='A' && cc<='Z'){
            res+=cc;
        }
        else if (cc=='('){
            s.push(cc);
        }
        else if(cc==')'){
            while(!s.isEmpty() && s.peek()!='('){
                res+=s.pop();
            }
            s.pop();
        }
        else{
            while(!s.isEmpty() && prec(s.peek())>=prec(cc)){
                res+=s.pop();
            }
            s.push(cc);
        }
    }
    while(!s.isEmpty()){
        res+=s.pop();
    }

    cout<<res<<endl;

}

int main(){

    string s;
    cout<<"enter the string"<<endl;
    cin>>s;
    convert(s);
    


    return 0;
}