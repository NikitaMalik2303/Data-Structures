#include <iostream>
using namespace std;

void insertionSort(int arr[],int n){

    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    return ;

}

int main(){

    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    insertionSort(arr,n);

    for(int i =0;i<n;i++){
        cout<<arr[i]<<"\t";
    }


    return 0;
}