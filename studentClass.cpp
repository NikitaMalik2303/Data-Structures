#include <iostream>
#include <string.h>
using namespace std;

class student{
private:
    string name;
    int grade;
    int rollno;

public:
    int roll();
    void read(student s[],int n);
    void display(student s[],int n);
};

void student::read(student s[],int n){
    for(int i=0;i<n;i++){
        cout<<"enter the name"<<endl;
        cin>>s[i].name;
        cout<<"enter the rollno"<<endl;
        cin>>s[i].rollno;
        cout<<"enter the marks"<<endl;
        cin>>s[i].grade;
    }
}

void student::display(student s[],int n){
    for(int i=0;i<n;i++){
        cout<<"name:"<<s[i].name<<"\t";
        cout<<"rollno:"<<s[i].rollno<<"\t";
        cout<<"grade:"<<s[i].grade<<"\t";
        cout<<endl;
    }
}

int student::roll(){
    return rollno;
}

void sorting(student s[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(s[j].roll()>s[j+1].roll()){
                swap(s[j],s[j+1]);
            }
        }
    }
}

int main(){

    student s[100];
    int n;
    cout<<"enter the number of objects"<<endl;
    cin>>n;
    s[0].read(s,n);
    sorting(s,n);
    s[0].display(s,n);
    return 0;
}
