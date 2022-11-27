#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int n){
        data = n;
        next = prev = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head = tail = NULL;
    }

    void insertTail(Node *&head, int val){
        Node *temp = new Node(val);
        if(tail == NULL){
            head = tail = temp;
            return;
        }
        Node *curr = head;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void deleteTail(Node *&head){
        Node *curr = head;
        if(tail == NULL){
            return;
        }
        if(head->next == NULL){
            delete head;
        }
        Node *var = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        delete var;
    }

    void deletePosition(Node *&head, int index){
        Node *temp ;
        Node *curr = head;
        int count = 1;
        while(count<=index && curr!=NULL){
            count++;
            curr = curr->next;            
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        cout<<curr->data<<"  ";
        //delete curr;
    }
    
    void print(Node *head){
        Node *curr = head;
        while(curr!=NULL){
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;
    }

};

void concatenate(DoublyLinkedList a, DoublyLinkedList b){
    Node* curr = b.head;
    while(curr!=NULL){
        a.insertTail(a.head , curr->data);
        curr = curr->next;
    }
}

int main(){

    DoublyLinkedList a;
    DoublyLinkedList b;
    for(int i =1; i<6;i++){
        a.insertTail(a.head,i);
    }
    a.print(a.head);

    for(int i =6; i<10;i++){
        b.insertTail(b.head,i);
    }
    b.print(b.head);

    concatenate(a,b);

    a.print(a.head);

    return 0;
}