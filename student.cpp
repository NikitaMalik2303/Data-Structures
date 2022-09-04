#include <iostream>
#include <string.h>
using namespace std;

class student{

    private:
    string name;
    int rollno;
    int grade;

    public:
    void read(student arr[],int n);
    void display(student arr[],int n);
    void sort(student arr[],int n);
};

void student::read(student arr[],int n){
    for(int i=0;i<n;i++){
        cout<<"enter the name of the student"<<endl;
        cin>>arr[i].name;
        cout<<"enter the rollno of the student"<<endl;
        cin>>arr[i].rollno;
        cout<<"enter the grade"<<endl;
        cin>>arr[i].grade;
    }    
}

void student::display(student arr[],int n){
    for(int i=0;i<n;i++){
        cout<<"Name : "<<arr[i].name<<endl;
        cout<<"Rollno : "<<arr[i].rollno<<endl;
        cout<<"Grade : "<<arr[i].grade<<endl;
    }
    
}

void student::sort(student arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].rollno>arr[j+1].rollno){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){

    student arr[100];
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    arr[0].read(arr,n);
    arr[0].sort(arr,n);
    arr[0].display(arr,n);

    return 0;
}