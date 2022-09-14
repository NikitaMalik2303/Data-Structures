#include <iostream>
using namespace std;

class sparseMatrix{

    int row,col,value;
    public:
    void create(int r,int c,int v){
        row = r;
        col = c;
        value = v;
    }
    void display(sparseMatrix arr[]){
        int index=1,counter=0;
        for(int i=0;i<arr[0].row;i++){
            for(int j=0;j<arr[0].col;j++){
                if(arr[index].row==i && arr[index].col==j){
                    cout<<arr[index++].value<<"\t";
                }
                else{
                    cout<<counter<<"\t";
                }
            }
            cout<<endl;
        }
    }
    sparseMatrix transpose(sparseMatrix arr[]){
        sparseMatrix trans[10];
        trans[0].create(arr[0].col,arr[0].row,arr[0].value);
        int index1=1,index2=1;
        for(int i=0;i<arr[0].value;i++){
            for(int j=0;j<arr[0].col;j++){
                if(arr[i].col==j){
                    trans[index2].create(arr[i].col,arr[i].row,arr[i].value);
                    index2++;
                }
            }
        }
        
        return trans;
    }


};

int main(){

    int row,col,index=1,count=0;
    sparseMatrix arr[10];
    cout<<"enter the number of rows"<<endl;
    cin>>row;
    cout<<"enter the number of columns"<<endl;
    cin>>col;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int temp;
            cin>>temp;
            if(temp!=0){
                arr[index].create(i,j,temp);
                count++;
            }
        }
    }
    arr[0].create(row,col,count);

    arr[0].display(arr);
    sparseMatrix trans[10];
    cout<<"the transpose of the matrix is "<<endl;

    trans = arr[0].transpose(arr);

    trans[0].display(trans);

    return 0;
}