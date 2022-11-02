#include <iostream>
using namespace std;

int main(){

    int n,x,count=0;
    cout<<"enter the value of x"<<endl;
    cin>>x;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int result =0;
    while(count<n){

        result+= pow(-1,count)*pow(x,2*count+1)/(2*count+1);
        count++;
    }
    cout<<result;

    return 0;
}