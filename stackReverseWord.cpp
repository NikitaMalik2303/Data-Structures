#include <iostream>
#include <string.h>
#include<stack>
using namespace std;

void reverse(string str){
    stack<string> s;
    string word="";
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            s.push(word);
            word="";
        }
        else{
            word +=str[i];
        }
    }

    s.push(word);

    while(!s.empty()){
        cout<<s.top()<<"\t";
        s.pop();
    }
    cout<<endl;

    return;
}

int main(){

    cout<<"enter the string"<<endl;
    string str;
    getline(cin,str);
    reverse(str);

    return 0;
}