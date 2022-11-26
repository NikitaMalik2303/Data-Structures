#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* lchild;
    Node* rchild;
    Node(int n){
        data = n;
        lchild = rchild = NULL;
    }
};

bool ancestors(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(ancestors(root->lchild,key) || ancestors(root->rchild,key)){
        cout<<root->data<<"  ";
        return true;
    }
    return false;
}

int main(){

    Node *root = new Node(1);
    root->lchild = new Node(2);
    root->rchild = new Node(3);
    root->lchild->lchild = new Node(4);
    root->lchild->rchild = new Node(5);
    root->rchild->lchild = new Node(6);
    root->rchild->rchild = new Node(7);

    int key;
    cin>>key;
    cout<<ancestors(root,key);

    return 0;
}