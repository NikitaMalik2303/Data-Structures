#include <iostream>
using namespace std;

int main(){

    int n,m;
    cout<<"enter the value of m"<<endl;
    cin>>m;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int a[m][n],b[m][n],c[m][n];
    cout<<"enter the elements of matrix a"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"enter the elements of matrix b"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    for( int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            c[i][j]=max(a[i][j],b[i][j]);
        }
    }
    cout<<"the matrix a is"<<endl;
    for( int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"the matrix b is"<<endl;
    for( int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"the matrix c is"<<endl;
    for( int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }
    



    return 0;
}