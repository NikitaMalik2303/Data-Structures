#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){

    int start=0,end=n-1,mid;
    do{
        mid = (start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }while(start<=end);

    return -1;

}

int main(){

    int n,key;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the key"<<endl;
    cin>>key;

    int pos = binarySearch(arr,n,key);

    if(pos!=-1){
        cout<<"the element is found at position "<<pos+1<<endl;
    }
    else{
        cout<<"the element is not found in the given array"<<endl;
    }


    return 0;
}