#include <iostream>
using namespace std;

int main(){

    int pos,strlen,sublen;
    char str[100],substr[100];
    cout<<"please enter the string"<<endl;
    cin>>str;
    cout<<"please enter the substring"<<endl;
    cin>>substr;
    cout<<"enter the position at which you want to enter the substring"<<endl;
    cin>>pos;
    strlen=sublen=0;
    for(int i=0;str[i]!='\0';i++){
        strlen++;
    }
    for(int i=0;substr[i]!='\0';i++){
        sublen++;
    }
    char altstr[100];
    for(int i=0;i<strlen;i++){
        altstr[i]=str[i];
    }
    int tlen = strlen + sublen;
    for(int i=0;i<sublen;i++){
        str[i+pos]=substr[i];
    }
    for(int i=pos;altstr[i]!='\0';i++){
        str[i+sublen]=altstr[i];
    }
    str[tlen]='\0';
    cout<<str;

    return 0;
}