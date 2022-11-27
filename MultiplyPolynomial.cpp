#include <iostream>
using namespace std;

class Node{
    public:
    int coeff;
    int exp;
    Node* next;
    Node(int c, int e){
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* front;
    Node* rear;
    LinkedList(){
        front = rear = NULL;
    }
    void addAtEnd(Node* temp){
        if(rear==NULL){
            front = rear = temp;
        }
        rear->next = temp;
        rear = temp;
    }
};

class Polynomial{
    
    public:
    LinkedList* termlist;
    Polynomial(){
        termlist = new LinkedList();
    }

    void add(int c, int e){
        Node* temp = new Node(c,e);
        termlist->addAtEnd(temp);
    }

    void simplify(){
        Node* curr = termlist->front;
        Node* rest = curr;
        while(curr!=NULL){
            rest = curr;
            while(rest->next!=NULL){
                if(curr->exp == rest->next->exp){
                    curr->coeff += rest->next->coeff;
                    Node* temp = rest->next;
                    rest->next = temp->next;
                    delete temp;
                }
                rest = rest->next;
            }
            curr = curr->next;
        }
    }

    void arrange(){
        Node* curr = termlist->front;
        while(curr!=NULL){
            Node* rest = curr->next;
            while(rest!=NULL){
                if(curr->exp<rest->exp){
                    swap(curr->exp, rest->exp);
                    swap(curr->coeff, rest->coeff);
                }
                rest = rest->next;
            }
            curr = curr->next;
        }
    }

    void multiply(Polynomial* A, Polynomial* B){
        Node* a_front = A->termlist->front;
        Node* b_front = B->termlist->front;
        while(a_front!=NULL){
            b_front = B->termlist->front;
            while(b_front!=NULL){
                Node* temp = new Node(a_front->coeff * b_front->coeff, a_front->exp + b_front->exp);
                termlist->addAtEnd(temp);
                b_front = b_front->next;
            }
            a_front = a_front ->next;
        }
        simplify();
        arrange();
    }

    void print(){
        Node* temp = termlist->front;
        while(temp!=NULL){
            cout<<"("<<temp->coeff<<" , "<<temp->exp<<")"<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

int main(){

    Polynomial* a = new Polynomial();
    Polynomial* b = new Polynomial();
    Polynomial* c = new Polynomial();

    //a->add(4,2);
    //a->add(3,3);
    //a->add(0,0);
    a->add(1,0);
    a->add(1,1);
    cout<<"Polynomial A"<<endl;
    a->arrange();
    a->simplify();
    a->print();

    //b->add(2,3);
    //b->add(2,2);
    b->add(1,1);
    b->add(1,0);
    cout<<"Polynomial B"<<endl;
    b->print();

    c->multiply(a,b);
    c->print();

    return 0;
}