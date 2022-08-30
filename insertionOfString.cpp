#include <iostream>
using namespace std;

int main()
{
    char str[100],substr[100],dstr[100];
    int pos,strlen=0,sublen=0;
    cout<<"enter the string"<<endl;
    cin>>str;
    cout<<"enter the substring"<<endl;
    cin>>substr;
    cout<<"enter the position at which you want to enter the string"<<endl;
    cin>>pos;
    for(int i=0;str[i]!='\0';i++){
        dstr[i]=str[i];
        strlen++;
    }
    for(int i=0;substr[i]!='\0';i++){
        sublen++;
    }
    for(int i=0;substr[i]!='\0';i++){
        str[i+pos]=substr[i];
    }
    for(int i=pos;dstr[i]!='\0';i++){
        str[i+sublen]=dstr[i];
    }
    str[strlen+sublen]='\0';

    cout<<str;


    return 0;
}
