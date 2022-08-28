#include <iostream>
using namespace std;

void bubbleSort(int arr[],int i,int n){

    if(i==n-1){
        return ;
    }
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    bubbleSort(arr,++i,n);

}

int main(){

    int n;
    cout<<"please enter the value of n"<<endl;
    cin>>n;
    int arr[100];
    cout<<"please enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubbleSort(arr,0,n);

    cout<<"the sorted array is "<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }


    return 0;
}