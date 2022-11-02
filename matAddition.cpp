#include <iostream>
using namespace std;

int main(){

    int a[100][100],b[100][100],c[100][100];
    int n,m;
    cout<<"enter the number of rows of the array"<<endl;
    cin>>m;
    cout<<"enter the number of columns of the array"<<endl;
    cin>>n;
    cout<<"enter the elements of the array a"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    cout<<"enter the elements of the array b"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    
    //printing the elements of the array c

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}