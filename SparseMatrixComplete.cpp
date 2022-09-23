#include <iostream>
using namespace std;

class SparseMatrix{

    int row,col,value;
    public:

    void create(int i, int j, int val){
        row = i;
        col = j;
        value = val;
    }

    void  display(SparseMatrix arr[]){

        int index =1;
        for(int i=0;i<arr[0].row;i++){
            for(int j=0;j<arr[0].col;j++){
                if(arr[index].row == i && arr[index].col == j){
                    cout<<arr[index++].value<<"\t";
                }
                else{
                    cout<<'0'<<"\t";
                }
            }
            cout<<endl;
        }

    }

    void transpose(SparseMatrix a[] , SparseMatrix b[]){

        a[0].col = b[0].row;
        a[0].row = b[0].col;
        a[0].value = b[0].value;

        int index =1;

        for(int i=0;i<b[0].col;i++){
            for(int j=1;j<=b[0].value;j++){
                if(b[j].col==i){
                    a[index].col = b[j].row;
                    a[index].row = b[j].col;
                    a[index++].value = b[j].value;
                
                }
            }
        }

    }

    void fastTranspose(SparseMatrix a[],SparseMatrix b[]){

        a[0].col = b[0].row;
        a[0].row = b[0].col;
        a[0].value = b[0].value;
        int rowTerms[b[0].col]={0};
        int position[b[0].col];

        for(int i=1;i<=b[0].value;i++){
            rowTerms[b[i].col]++;
        }
        position[0]=1;
        for(int i=1;i<b[0].value;i++){
            position[i]=rowTerms[i-1]+position[i-1];
        }
        for(int i=1;i<=b[0].value;i++){
            int index = position[b[i].col]++;
            a[index].col = b[i].row;
            a[index].row = b[i].col;
            a[index].value = b[i].value;
        }

    }

};

int main(){

    int row,col,index =1,count=0;
    SparseMatrix arr[10] ,trans[10];
    cout<<"please enter the value of row"<<endl;
    cin>>row;
    cout<<"please enter the value of col"<<endl;
    cin>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int temp;
            cin>>temp;
            if(temp!=0){
                arr[index++].create(i,j,temp);
                count++;
            }
        }
    }

    arr[0].create(row,col,count);

    arr[0].display(arr);
    cout<<endl;
    cout<<"Transpose"<<endl;
    arr[0].transpose(trans,arr);
    trans[0].display(trans);

    cout<<endl;
    cout<<"Fast transpose"<<endl;
    arr[0].transpose(trans,arr);
    trans[0].display(trans);  

    return 0;
}