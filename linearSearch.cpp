#include <iostream>
using namespace std;

int linearSearch(int arr[],int n,int key){

    int i,pos=-1;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            pos=i;
            break;
        }
    }

    return pos;

}

int main(){

    int n,key,i;
    cout<<"please enter the value of n"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the element to search for"<<endl;
    cin>>key;

    int pos=linearSearch(arr,n,key);
    if(pos!=-1){
        cout<<"the element is found at position "<<pos+1<<endl;
    }
    else{
        cout<<"the element is not found in the array"<<endl;
    }

    return 0;
}