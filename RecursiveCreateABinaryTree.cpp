#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int n){
        data = n;
        lchild = rchild = NULL;
    }
};

Node * create(){
    int value;
    cin>>value;
    if(value == 0){
        return NULL;
    }
    Node *temp = new Node(value);
    temp->lchild = create();
    temp->rchild = create();

    return temp;
}

void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"  ";
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(Node * root){
    if(root==NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<"  ";
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->lchild);
    cout<<root->data<<"  ";
    inorder(root->rchild);
}

int main(){

    Node * root = create();
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;


    return 0;
}