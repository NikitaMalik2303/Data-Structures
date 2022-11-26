#include<iostream>
#include <stack>
#include <math.h>
using namespace std;

void prefixEvaluation(string str){
    stack<int> s;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            s.push(str[i]-'0');
        }
        else {
            int op1,op2;
            op1=s.top();
            s.pop();
            op2= s.top();
            s.pop();
            switch (str[i]){
                case '^':
                    s.push(pow(op1,op2));
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
            }
        }
    }

    cout<<s.top()<<endl;

}

int main(){

    string str;
    cout<<"enter the string"<<endl;
    cin>>str;

    prefixEvaluation(str);

    cout<<"Answer"<<endl;

    return 0;
}