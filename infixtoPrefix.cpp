#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char ch){

    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return -1;
    }

}

string infixToPrefix(string str){
    reverse(str.begin(),str.end());
    stack<char> s;
    string res;

    for(int i=0;i<str.length();i++){
        if(str[i]==')'){
            str[i]='(';
        }
        else if(str[i]=='('){
            str[i]=')';
        }
    }

    for(int i=0;i<str.length();i++){

        if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'){
            res+=str[i];
        }
        else if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            while(!s.empty() && s.top()!='('){
                res+=s.top();
                s.pop();
            }
            if(!s.empty()){
                s.pop();
            }
        }
        else{
            if(str[i] == '^'){
                while(!s.empty() && prec(s.top())>=prec(str[i])){
                    res+=s.top();
                    s.pop();
                }
            }
            else{
                while(!s.empty() && prec(s.top())>prec(str[i])){
                res+=s.top();
                s.pop();
            }
            }
            
            s.push(str[i]);
        }        

    }

    while(!s.empty()){
        res+=s.top();
        s.pop();
    }

    reverse(res.begin(),res.end());
    return res;
}

int main(){

    string str;
    cout<<"enter the string"<<endl;
    getline(cin,str);

    cout<<infixToPrefix(str);


    return 0;
}