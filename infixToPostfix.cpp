#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int prec(char ch){
    if(ch=='^')
        return 3;
    else if (ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string str){
    stack<char> s;
    string res="";
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            while(!s.empty() && s.top()!='('){
                res+=s.top();
                s.pop();
            }
            if(!s.empty())
                s.pop();
        }
        else if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'){
            res+=str[i];
        }
        else{
            while(!s.empty() && prec(s.top())>prec(str[i])){
                res+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        
    }

    return res;
}

int main(){

    string str;
    cout<<"enter the string"<<endl;
    getline(cin,str);

    cout<<infixToPostfix(str);

    return 0;
}