#include <iostream>
using namespace std;

int main(){

    int i,len_1=0,len_2=0;
    char str_1[100],str_2[100];
    cout<<"enter the two strings"<<endl;
    cin>>str_1>>str_2;
    for(i=0;str_1[i]!='\0';i++){
        len_1++;
    }
    for(i=0;str_2[i]!='\0';i++){
        len_2++;
    }
    for(i=0;i<len_2;i++){
        str_1[len_1+i]=str_2[i];
    }
    str_1[len_1+len_2]='\0';
    cout<<str_1<<endl;

    return 0;
}
