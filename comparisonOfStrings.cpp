#include <iostream>
using namespace std;

int main(){

    char s1[100],s2[100];
    int len1,len2,flag =1;
    cout<<"enter the two strings to compare "<<endl;
    cin>>s1>>s2;
    len1=len2=0;
    for(int i=0;s1[i]!='\0';i++){
        len1++;
    }
    for(int i=0;s2[i]!='\0';i++){
        len2++;
    }

    if(len1!=len2){
        flag =0;
    }
    else{
        for(int i=0;i<len1;i++){
           if(s1[i]!=s2[i]){
            flag =0;
            break;
            }
        }
    }
    if(flag ==0){
        cout<<"unequal strings"<<endl;
    }
    else{
        cout<<"equal strings"<<endl;
    }

    return 0;
}
