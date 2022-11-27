#include <iostream>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node(string n){
        data = n;
        next = NULL;
    }
};

class LL{
    public:
    Node* head;
    void insert(Node* &head, string n){
        Node* temp = new Node(n);
        if(head == NULL){
            head = temp;
            return;
        }
        Node* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    void deleteNode(Node* &head, string n){
        if(head == NULL){
            return;
        }
        Node* curr = head;
        while(curr->next!=NULL){
            if(curr->next->data == n){
                Node* var = curr->next;
                curr->next = curr->next->next;
                delete var;
                return;
            }
            curr = curr->next;
        }
    }
    void print(Node* head){
        Node* curr = head;
        while(curr->next!=NULL){
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }
        cout<<"NULL";
    }
    
};

int main(){

    string str;
    getline(cin,str);
    Node* head = NULL;
    LL *list = new LL();
    string word = "";
    for(int i =0;i<str.length();i++){
        
        if(str[i]==32){
            list->insert(head,word);
            word = "";
        }
        else{
            word+=str[i];
        }
    }

    list->insert(head,word);

    list->print(head);


    return 0;
}