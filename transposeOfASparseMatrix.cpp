#include <iostream>
using namespace std;

class sparseMatrix{

    int row,col,value;
    public:
    void create(int r,int c,int v){
        row=r;
        col=c;
        value=v;
    }
    
    void display(sparseMatrix s[]){
        int index=1,counter=0;
        for(int i=0;i<s[0].row;i++){
            for(int j=0;j<s[0].col;j++){
                if(s[index].row == i && s[index].col==j){
                    cout<<s[index++].value<<"\t";
                }
                else{
                    cout<<counter<<"\t";
                }
            }
            cout<<endl;
        }
    }

};

int main(){

    sparseMatrix arr[10];

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

    return 0;
}