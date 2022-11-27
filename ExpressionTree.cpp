#include <iostream>
using namespace std;

#define space 5

class Node{
    public:
    char data;
    Node* lchild;
    Node* rchild;
    Node* next ;
    Node(char n){
        data = n;
        lchild = rchild = next = NULL;
    }
};

class stack{
    public:
    Node* head;
    stack(){
        head = NULL;
    }

    bool isEmpty(){
        return (head == NULL);
    }

    void push(Node* temp){
        if(head == NULL){
            head = temp;
        }
        temp->next = head;
        head = temp;
    }

    Node* pop(){
        if(head == NULL){
            cout<<"Stack is empty"<<endl;
            return NULL;
        }
        Node* temp = head;
        head = head -> next;
        return temp;
    }
};

Node* ExpressionTree(string str){
    stack *s = new stack();
    for(int i=0; i<str.length(); i++){
        if(str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z'){
            Node* temp = new Node(str[i]);
            s->push(temp);
        }
        else{
            Node* n2 = s->pop();
            Node* n1 = s->pop();
            Node* temp = new Node(str[i]);
            temp->rchild = n2;
            temp->lchild = n1;
            s->push(temp);
        }
    }

    return s->pop();
}

void evalauateExpressionTree(Node* root){
    if(root == NULL){
        return ;
    }
    evalauateExpressionTree(root->lchild);
    cout<<root->data<<" ";
    evalauateExpressionTree(root->rchild);
}

void print(Node* root, int level){
    if(root == NULL){
        return ;
    }
    level += space;
    print(root->rchild, level);
    for(int i=space; i<level; i++){
        cout<<"  ";
    }
    cout<<root->data<<endl;
    print(root->lchild,level);
}

int main(){

    string str = "ABC*+D/";
    Node* root = ExpressionTree(str);
    cout<<"Printing"<<endl;

    print(root,0);

    evalauateExpressionTree(root);

    return 0;
}