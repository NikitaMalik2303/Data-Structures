#include <iostream>
using namespace std;

int main(){

    char str_1[100],str_2[100];
    cout<<"enter the string"<<endl;
    cin>>str_1;
    cout<<"enter the substring"<<endl;
    cin>>str_2;
    int str_1len,j;
    for(str_1len=0;str_1[str_1len]!='\0';str_1len++);
    for(j=0;str_2[j]!='\0';j++){
        str_1[str_1len +j]=str_2[j];
    }
    str_1[str_1len +j]='\0';
    cout<<str_1;

    return 0;
}