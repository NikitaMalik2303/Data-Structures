#include <iostream>
using namespace std;

class time{
    private:
        int hour;
        int min;
        int sec;
    public:
        void read();
        void display();
        time add(time a);
        time difference(time a);

};

void time::read(){
    cout<<"Hour ?"<<endl;
    cin>>hour;
    cout<<"Minutes ?"<<endl;
    cin>>min;
    cout<<"Seconds ?"<<endl;
    cin>>sec;
}

void time::display(){
    cout<<hour<<":"<<min<<":"<<sec<<endl;
}

time time::add(time a){
    time c;
    c.sec = this->sec + a.sec;
    c.min = this->min + a.min + c.sec/60;
    c.hour = this->hour + a.hour + c.min/60;
    c.sec %=60;
    c.min %=60;
    return c;
}

time time::difference(time a){
    time d;
    int i =a.hour*3600+a.min*60+sec;
    int j = hour*3600+min*60+sec;
    if(i>j){
        if(a.sec<sec){
            a.min--;
            d.sec +=60;
        }
        d.sec = a.sec-sec;
        if(a.min<min){
            a.hour--;
            a.min+=60;
        }
        d.min = a.min-min;
        d.hour= a.hour - hour;
    }
    else{
        if(sec<a.sec){
            min--;
            sec +=60;
        }
        d.sec = sec-a.sec;
        if(min<a.min){
            hour--;
            min+=60;
        }
        d.min = min-a.min;
        d.hour= hour - a.hour;
    }
    return d;
}


int main(){

    time a,b,c,d;
    a.read();
    b.read();
    c=a.add(b);
    d=a.difference(b);
    c.display();
    d.display();

    return 0;
}