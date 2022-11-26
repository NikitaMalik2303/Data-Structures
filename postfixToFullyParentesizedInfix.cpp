#include <iostream>
using namespace std;

#define n 100

class stack{

    int top;
    string *arr;
    public:
    stack(){
        top=-1;
        arr= new string[n];
    }
    bool isEmpty(){
        return (top==-1);
    }
    bool isFull(){
        return (top==n-1);
    }
    string pop(){
        if(isEmpty()){
            cout<<"Stack is EMpty"<<endl;
            return "0";
        }
        return arr[top--];
    }
    void push(string x){
        if(isFull()){
            cout<<"stack is full"<<endl;
            return;
        }
        arr[++top]=x;
    }
    string peek(){
        if(isEmpty()){
            return "0";
        }
        return arr[top];
    }

};

void convert(string str){
    stack s;
    for(int i =0;i<str.length();i++){
        if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'){
            string word = "";
            word+=str[i];
            //word = str.substring(i,1);
            s.push(word);
        }
        else {
            string op2 = s.pop();
            string op1 = s.pop();
            string exp;
            exp = "(" + op1 + str[i] + op2 +")";
            s.push(exp);              
        }
    }

    cout<<s.pop()<<endl;
}

int main(){

    string str = "ab*cd/+";
    convert(str);

    return 0;
}