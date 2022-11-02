#include <iostream>
using namespace std;

int multiply(int a,int b){

    if(b==0){
        return 0;
    }
    return a + multiply(a,b-1);

}

int main(){

    int a,b;
    cout<<"enter the two numbers"<<endl;
    cin>>a>>b;

    cout<<"the multiplication of two numbers is "<<multiply(a,b);
    

    return 0;
}