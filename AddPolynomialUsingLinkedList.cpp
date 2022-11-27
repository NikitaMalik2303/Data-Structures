#include <iostream>
using namespace std;

class Node{
    public:
    int coeff;
    int exp;
    Node* next;
    Node(int c,int e){
        coeff =c;
        exp =e;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* front;
    Node* rear;
    LinkedList(){
        front = rear =NULL;
    }
    void addAtEnd(Node* temp){
        if(rear == NULL){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
};

class Polynomial{
    public:
    LinkedList *termlist;

    Polynomial(){
        termlist = new LinkedList();
    }

    void add(int c, int e){
        Node* temp = new Node(c,e);
        termlist->addAtEnd(temp);
    }

    Polynomial* addPolynomial(Polynomial* A, Polynomial* B){
        Node* a_front = A->termlist->front;
        Node* b_front = B->termlist->front;
        Polynomial* res = new Polynomial() ;

        while(a_front!=NULL || b_front!=NULL){
            if(a_front->exp > b_front->exp){
                res->add(a_front->coeff,a_front->exp);
                a_front = a_front->next;
            }
            else if(a_front->exp < b_front->exp){
                res->add(b_front->coeff,b_front->exp);
                b_front = b_front->next;
            }
            else{
                res->add(a_front->coeff + b_front->coeff , a_front->exp);
                a_front = a_front->next;
                b_front = b_front->next;
            }
        }
        
        if(a_front!=NULL){
            res->termlist->addAtEnd(a_front);
        }
        if(b_front!=NULL){
            res->termlist->addAtEnd(b_front);
        }

        return res;
    }

    void simplify(){
        Node* temp = termlist->front;
        Node* curr = termlist->front;
        while(temp!=NULL && temp->next!=NULL){
            curr = temp->next;
            while(curr!=NULL){
                if(temp->exp == curr->next->exp){
                    temp->coeff += curr->next->coeff;
                    Node* var = curr->next;
                    curr->next = curr->next->next;
                    delete var;
                }
                else{
                    curr = curr->next;
                }
            }
            temp = temp->next;
        }
    }

    void arrange(){
        Node* curr = termlist->front;
        while(curr!=NULL){
            Node* rest = curr->next;
            while(rest!=NULL){
                if(curr->exp < rest->exp){
                    swap(curr->coeff, rest->coeff);
                    swap(curr->exp, rest->exp);
                }
                rest = rest ->next;
            }
            curr = curr->next;
        }
    }

    void print(){
        Node* ac = termlist->front;
        while(ac!=NULL){
            cout<<"("<<ac->coeff<<","<<ac->exp<<")"<<"  ";
            ac = ac->next;
        }
        cout<<"NULL"<<endl;
    }
        
};

int main(){

    Polynomial *a ,*b;
    a = new Polynomial();
    b = new Polynomial();
    a->add(4,2);
    a->add(3,3);
    a->add(3,1);
    a->add(4,0);
    cout<<"Polynomial A"<<endl;
    a->arrange();
    a->print();

    b->add(2,3);
    b->add(2,2);
    b->add(2,1);
    b->add(4,0);
    cout<<"Polynomial B"<<endl;
    b->print();

    Polynomial *c = new Polynomial();
    c = c->addPolynomial(a,b);
    cout<<"Resultant Polynomial"<<endl;
    c->print();

    return 0;
}