#include <iostream>
using namespace std;

int minPos(int arr[],int i,int j){
    if(i==j){
        return i;
    }
    int k = minPos(arr,i+1,j);
    if(arr[i]<arr[k]){
        return i;
    }
    else{
        return k;
    }
}

void SelectionSort(int arr[], int i,int n){

    if(i==n){
        return;
    }

    int k =minPos(arr,i,n-1);

    if(k!=i){
        swap(arr[i],arr[k]);
    }
    
    SelectionSort(arr,i+1,n);

}

int main(){

    int n;
    int arr[100];
    cout<<"please enter the value of n"<<endl;
    cin>>n;
    cout<<"please enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    SelectionSort(arr,0,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }


    return 0;
}