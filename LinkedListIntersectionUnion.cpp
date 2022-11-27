#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int n){
        data = n;
        next = NULL;
    }
};

//class LinkedList{
//    public:
    void insert_head(Node* &head,int val){        
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }

    void insert_tail(Node* &head,int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            return;
        }
        Node* curr = head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = temp;
    }

    void deleteNode(Node* &head, int key){
        if(head == NULL){
            return ;
        }
        Node* prev= NULL;
        Node* curr = head;
        while(curr!=NULL && curr->data!=key){
            prev = curr;
            curr = curr->next;
        }
        if(curr== NULL){
            cout<<"Element not found"<<endl;
            return;
        }        
        prev->next = curr->next;
        delete curr;

    }

    void print(Node * head){
        Node* curr = head;
        while(curr!=NULL){
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;
    }
//};

bool isPresent(Node* head,int key){
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data == key){
            return true;
        }
        curr = curr->next;
    }
    return false;
}



Node* intersection(Node* head1, Node* head2){
    Node* curr1 = head1;
    Node* curr2 = head2;
    Node* newLL = NULL;
    while(curr1!=NULL){
        if(isPresent(head2,curr1->data)){
            insert_tail(newLL,curr1->data);
        }
        curr1 = curr1->next;            
    }
    return newLL;

}

Node* unionLL(Node* head1, Node* head2){
    Node* curr1 = head1;
    Node* curr2 = head2;
    Node* newLL = NULL;
    while(curr1!=NULL){
        insert_head(newLL,curr1->data);
        curr1 = curr1->next;
    }
    while(curr2!=NULL){
        if(!isPresent(newLL,curr2->data)){
            insert_head(newLL,curr2->data);
        }
        curr2 = curr2 ->next;
    }
    return newLL;
}

int main(){

    Node* head1 = NULL;
    for(int i =1;i<7;i++){
        insert_tail(head1,i);
    }
    print(head1);

    Node* head2 = NULL;
    insert_tail(head2,2);
    insert_tail(head2,4);
    insert_tail(head2,6);
    insert_tail(head2,8);
    insert_tail(head2,10);
    print(head2);

    cout<<"intersection"<<endl;

    Node* newLL = intersection(head1,head2);
    print(newLL);

    cout<<"union"<<endl;

    Node* newUnion = unionLL(head1,head2);
    print(newUnion);

    return 0;
}