#include <iostream>
using namespace std;

int main(){

    int m,n,q,p,k ;
    int a[10][10],b[10][10],c[10][10];
    cout<<"enter the number of rows and columns in the first matrix"<<endl;
    cin>>m>>n;
    cout<<"enter the number of rows and columns in the second matrix"<<endl;
    cin>>p>>q;
    if(n!=q){
        exit(0);
    }

    //input of elements of first array
    cout<<"enter the elements of the first matrix"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    //input of elements of first array
    cout<<"enter the elements of the second matrix"<<endl;

    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>b[i][j];
        }
    }

    //matrix multiplication

    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    //printing the resultant matrix

    for(int i=0;i<m;i++){
        for (int j=0;j<q;j++){
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}