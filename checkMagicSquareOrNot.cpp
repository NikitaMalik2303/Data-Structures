#include <iostream>
using namespace std;

int main(){

    int m,n;
    int a[10][10];
    cout<<"enter the number of rows and columns of the matrix"<<endl;
    cin>>m>>n;
    if(m!=n){
        exit(0);
    }
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int rowSum[10],colSum[10],dSum=0,flag =1;

    for(int i=0;i<m;i++){
        rowSum[i]=colSum[i]=0;
        for(int j=0;j<n;j++){
            rowSum[i]+=a[i][j];
            colSum[i]+=a[j][i];
            if(i==j){
                dSum+=a[i][j];
            }
        }
    }

    for(int i=0;i<m;i++){
        if(rowSum[i]!=colSum[i]){
            flag =0;
        }
        else if(rowSum[i]!=dSum){
            flag =0;
        }
    }   

    if(flag ==1){
        cout<<"the matrix is a magic square matrix"<<endl;
    }
    else{
        cout<<"the matrix is not a magic square matrix"<<endl;
    }

    return 0;
}