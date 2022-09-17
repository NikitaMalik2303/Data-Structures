#include <iostream>
#include <stack>
using namespace std;

class car{

    int numPlate;
    int N,n;
    stack<int> s;
    stack<int> b;
    int arr[100][2];

    public:
    car(int n);
    void arrival(int num);
    void departure(int num);
    int size();
    void countArrival(int num);
    void countDeparture(int num);
    bool isFound(int num);
};

car::car(int n){
    this->n = n;
    N=0;
}

void car::arrival(int num){
    if(s.size()==n){
        cout<<"no space for car parking"<<endl;
        return ;
    }
    s.push(num);
    countArrival(num);
    N++;
}

void car::departure(int num){
    if(!isFound(num)){
        cout<<"no such car in garage"<<endl;
        return;
    }
    while(s.top()!=num){
        b.push(s.top());
        countDeparture(s.top());
        s.pop();
    }
    int elem = s.top();
    s.pop();
    N--;
    while(!b.empty()){
        s.push(b.top());
        b.pop();
    }
    cout<<"the car removed has the following number "<<elem<<endl;
    int value;
    for(int i=0;i<N;i++){
        if(arr[i][0]==elem){
            value = arr[i][1];
            break;
        }
    }
    cout<<"the car has been already removed following number of times from the gargage "<<value<<endl;

}

bool car::isFound(int num){
    for(int i=0;i<N;i++){
        if(arr[i][0]==num){
            return true;
            break;
        }
    }
    return false;
}

int car::size(){
    return N;
}

void car::countArrival(int num){
    arr[N][0]=num;
    arr[N][1]=0;
}

void car::countDeparture(int num){
    for(int i=0;i<N;i++){
        if(arr[i][0]==num){
            arr[i][1]++;
        }
    }
}

int main(){

    int x,n;
    cout<<"enter the size of the garage"<<endl;
    cin>>n;
    car c(n);
    
    char ch='y';
    do{
    
        cout<<"\n*press 1 for arrival of the car"<<endl;
        cout<<"press 2 for departure of the car"<<endl;
        cout<<"press 3 to view number of cars in garage right now"<<endl;
        cout<<"press 4 to exit*\n"<<endl;
        cin>>x;
        switch(x){
        case 1:
            int num;
            cout<<"enter the number of car"<<endl;
            cin>>num;
            c.arrival(num);
            break;
        case 2:
            cout<<"enter the number of the car"<<endl;
            cin>>num;
            c.departure(num);
            break;
        case 3:
            cout<<"the number of cars in the garge right now is "<<c.size()<<endl;
            break;
        case 4:
            cout<<"exit successful"<<endl;
            ch='n';
            break;
        }


    }while(ch=='y');
    

    return 0;
}
