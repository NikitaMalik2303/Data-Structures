#include <iostream>
using namespace std;

int main(){

    int i;
    char str[100];
    cout<<"enter the string"<<endl;
    cin>>str;
    for(i=0;str[i]!='\0';i++);
    cout<<"the length of the string is "<<i<<endl;


    return 0;
}
