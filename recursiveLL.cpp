#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next ;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class LL{
    Node * head;
    public:
    Node *insert(Node *head,int value){
        if(head == NULL){
            Node *temp = new Node(value);
            return  temp;
        }
        else{
            head->next = insert(head->next,value);
        }
        return head;
    }
    void display(Node *head){
        if(head == NULL){
            return;
        }
        cout<<head->data<<"->";
        display(head->next);
    }
};

int main(){

    Node *head =NULL;
    LL lst;
    head = lst.insert(head,1);
    head = lst.insert(head,2);
    head = lst.insert(head,3);
    lst.display(head);

    return 0;
}