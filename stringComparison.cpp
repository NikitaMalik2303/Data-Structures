#include <iostream>
#include <string.h>
using namespace std;

int main(){

    char str_1[100],str_2[100];
    cout<<"enter the first string"<<endl;
    cin>>str_1;
    cout<<"enter the second string"<<endl;
    cin>>str_2;
    if(strcmp(str_1,str_2)==0){
        cout<<"the strings are equal"<<endl;
    }
    else{
        cout<<"the strings are not equal"<<endl;
    }

    return 0;
}