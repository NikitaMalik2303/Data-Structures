#include <iostream>
using namespace std;

class smt{

    int row,col,val;
    public:
    void create(int i,int j,int k){
        row=i;
        col=j;
        val=k;
    }
    void transpose(smt a[],smt b[]){
        a[0].row = b[0].col;
        a[0].col = b[0].row;
        a[0].val = b[0].val;
        int terms = b[0].val;
        int nCol[b[0].col]={0};
        int pos[b[0].col];
        for(int i=1;i<terms;i++){
            nCol[b[i].col]++;
        }
        pos[0]=1;
        for(int i=1;i<terms;i++){
            pos[i]=pos[i-1]+nCol[i-1];
        }
        for(int i=1;i<terms;i++){
            int index = pos[b[i].col]++;
            a[index].row=b[i].col;
            a[index].col=b[i].row;
            a[index].val=b[i].val;
        }
    }
    void display(smt b[]){
        int index =1;
        for(int i=0;i<b[0].row;i++){
            for(int j=0;j<b[0].col;j++){
                if(b[index].row==i && b[index].col==j){
                    cout<<b[index].val<<"\t";
                    index++;
                }
                else{
                    cout<<'0'<<"\t";
                }
            }
            cout<<endl;
        }
    }

};


int main(){

    smt arr[10];
    smt trans[10];
    int row,col,count,index=1;
    cout<<"enter the number of rows"<<endl;
    cin>>row;
    cout<<"enter the number of columns"<<endl;
    cin>>col;
    count=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int temp;
            cin>>temp;
            if( temp!=0){   
                arr[index].create(i,j,temp);
                count++;
                index++;
            }
        }
    }
    arr[0].create(row,col,count);
    cout<<"printing the sparse matrix"<<endl;
    arr[0].display(arr);
    arr[0].transpose(trans,arr);
    trans[0].display(trans);

    return 0;
}