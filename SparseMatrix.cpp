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
        int index = 1;
        for(int i=0;i<s[0].row;i++){
            for(int j=0;j<s[0].col;j++){
                if(s[index].row==i && s[index].col==j){
                    cout<<s[index++].value<<"\t";
                }
                else{
                    cout<<"0"<<"\t";
                }
            }
            cout<<endl;
        }
    }

    void transpose(sparseMatrix s[],sparseMatrix t[]){
        int index =1;
        t[0].row=s[0].col;
        t[0].col=s[0].row;
        t[0].value=s[0].value;
        for(int i=0;i<s[0].col;i++){
            for(int j=1;j<=s[0].value;j++){
                if(s[j].col==i){
                    t[index].col=s[j].row;
                    t[index].row = s[j].col;
                    t[index].value = s[j].value;
                    index++;
                }
                
            }
        }
    }

};

int main(){

    sparseMatrix arr[10];
    sparseMatrix trans[10];

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
    arr[0].transpose(arr,trans);
    trans[0].display(trans);

    return 0;
}