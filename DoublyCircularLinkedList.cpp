#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int n){
        data = n;
        next = prev = NULL;
    }
};

class CDLL{
    public:
    Node* head;
    void insert(Node* &head, int n){
        Node* temp = new Node(n);
        if(head == NULL){
            head = temp;
            head->next = head->prev = temp;
            return;
        }
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        //head = temp;
    }
    void deleteNode(Node* &head, int n){
        if(head == NULL){
            return;
        }
        Node* curr = head;
        while(curr->next!=head){
            if(curr->data == n){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }
    void print(Node* head){
        Node* curr = head;
        while(curr->next!=head){
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }
    }
    
};



int main(){

    CDLL a;
    a.head = NULL;

    for(int i=0; i<7;i++){
        a.insert(a.head,i);
    }

    a.print(a.head);
    cout<<endl;

    cout<<"After deleting"<<endl;

    a.deleteNode(a.head,5);
    a.print(a.head);

    return 0;
}