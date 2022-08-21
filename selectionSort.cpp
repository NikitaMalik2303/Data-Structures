#include <iostream>
using namespace std;

void selectionSort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int min_pos = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_pos]){
                min_pos=j;
            }
        }
        swap(arr[i],arr[min_pos]);
    }
    return ;

}

int  main(){

    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionSort(arr,n);

    cout<<"the sorted array is"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }


    return 0;
}