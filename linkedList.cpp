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

class linkedList{
    Node *head;
    public:
    void insertAtHead(Node* &head,int value){
        Node *temp = new Node(value);
        if(head == NULL){
            head = temp;
            return ;
        }
        temp->next = head;
        head = temp;
    }
    void insertAtEnd(Node *&head,int value){
        Node *temp = new Node(value);
        if(head == NULL){
            head = temp;
            return;
        }
        Node *curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    void insertBeforeElem(Node *&head,int data,int elem){
        Node *temp = new Node(data);
        Node *curr= head;
        while(curr->next->data!=elem){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    void insertAfterElem(Node * &head, int data,int elem){
        Node *temp = new Node(data);
        Node * curr = head;
        while(curr->data!=elem){
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = temp;
    }
    int deleteNode(Node * &head, int elem){
        if(head == NULL){
            cout<<"Empty LL"<<endl;
            return -1;
        }
        Node *curr = head;
        while(curr->next->data !=elem && curr->next!=NULL){
            if(curr->next==NULL){
                cout<<"element you want to delete is not found in the linked list"<<endl;
                return -1;
            }
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        int value = temp->data;
        delete temp;
        return value;
    }
    void reverse(Node *&head){
        Node *currptr,*nextptr,*prevptr;
        currptr = head;
        nextptr = prevptr = NULL;
        while(currptr !=NULL){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        head = prevptr;
    }
    void sort(Node *&head){
        Node *curr = head;
        while(curr!=NULL){
            Node *nextptr = curr;
            while(nextptr!=NULL){
                if(nextptr->data < curr->data){
                    swap(nextptr->data,curr->data);
                }
                nextptr = nextptr->next;
            }
            curr = curr->next;
        }
    }
    void deleteAlternateElement(Node *&head){
        if(head == NULL){
            cout<<"Linked List is empty"<<endl;
            return;
        }
        Node *temp = head;
        while(temp !=NULL && temp->next!=NULL){
            temp->next = temp->next->next;
            temp = temp->next;
        }
    }
    void insertSortedElem(Node *&head,int elem){
        sort(head);
        Node *temp = new Node(elem);
        Node *curr = head;
        if(elem > head->data && head->next == NULL){
            temp->next = head;
            head = temp;
            return;
        }
        while(curr->next->data<elem){
            curr=curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }


    void display(Node * & head){
        if(head == NULL){
            cout<<"Linked List is empty"<<endl;
            return;
        }
        Node * curr = head;
        while(curr!=NULL){
            cout<<curr->data<<"->";
            curr= curr->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){

    Node * head = NULL;
    linkedList list;
    list.insertAtHead(head,145);
    list.insertAtEnd(head,102);
    list.insertAtEnd(head,399);
    list.insertAtEnd(head,45);
    list.insertAtHead(head,545);
    list.display(head);
    list.sort(head);
    list.display(head); 
    list.display(head);                                                                                                                                                                                                    
    //list.reverse(head);
    list.insertSortedElem(head,200);

    list.display(head);

    return 0;
}