#include <iostream>
using namespace std;

int main(){

    char str[100],substr[100];
    cout<<"enter the string"<<endl;
    cin>>str;
    cout<<"enter the sub string to be deleted"<<endl;
    cin>>substr;
    int i=0,j=0,flag,pos,strlen=0,sublen=0;
    for(int i=0;str[i]!='\0';i++){
        strlen++;
    }
    for(int i=0;substr[i]!='\0';i++){
        sublen++;
    }
    while(str[i]!='\0'){
        if(str[i]==substr[0]){
            flag =1;
            while(substr[j]!='\0'){
                if(str[i+j]!=substr[j]){
                    flag =0;
                    break;
                }
                j++;
            }
            if(flag ==1){
                pos=i;
            }
        }
        i++;
    }
    for(int i=pos;i<=strlen-sublen;i++){
        str[i]=str[i+sublen];
    }
    cout<<str;

    return 0;
}
