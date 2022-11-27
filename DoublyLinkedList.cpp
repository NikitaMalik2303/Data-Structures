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

    void insertBeforeElem(Node *&head, int elem, int data){
        if(head == NULL){
            return;
        }
        Node *curr = head;
        while(curr!=NULL && curr->data!=elem){
            curr = curr->next;
        }
        Node* temp = new Node(data);
        temp->next = curr;
        temp->prev = curr->prev;
        curr->prev->next = temp;
        curr->prev = temp;
    }

    void insertAfterElement(Node *&head, int elem, int data){
        if(head == NULL){
            return;
        }
        Node *curr = head;
        while(curr!=NULL && curr->data!=elem){
            curr = curr->next;
        }
        Node* temp = new Node(data);
        temp->next = curr->next;
        temp->prev = curr;
        curr->next->prev = temp;
        curr->next = temp;
    }

    void insertAtPosition(Node *&head, int index, int data){
        Node *temp = new Node(data);
        int count = 1;
        Node *curr = head;
        while(count<index){
            curr = curr->next;
            count++;
        }
        temp->next = curr->next;
        temp->prev = curr->prev;
        curr->next->prev = temp;
        curr->next = temp;
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

    void reverse(Node *&head){
        Node* curr = head;
        Node* nextptr = NULL;
        Node* prevptr = NULL;
        tail = curr;
        while(curr!=NULL){
            nextptr = curr->next;
            curr->next = curr->prev;
            prevptr = curr;
            curr = nextptr;
        }
        head = prevptr;
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

int main(){

    DoublyLinkedList a;
    Node *head = NULL;
    for(int i =0; i<7;i++){
        a.insertTail(head, i);
    }

    a.print(head);

    cout<<"Reverse"<<endl;
    a.reverse(head);
    a.print(head);

    a.insertTail(head,7);
    a.print(head);
    
    cout<<"Insert After Element"<<endl;
    a.insertAfterElement(head,3,30);
    a.print(head);

    a.deletePosition(head,4);
    a.print(head);

    return 0;
}