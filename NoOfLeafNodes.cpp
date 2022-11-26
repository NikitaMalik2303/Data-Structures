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

int leafNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->lchild == NULL and root->rchild == NULL){
        return 1;
    }
    return leafNodes(root->lchild) + leafNodes(root->rchild) ;
    
}

int main(){

    Node *root = new Node(1);
    root->lchild = new Node(2);
    root->rchild = new Node(3);
    root->lchild->lchild = new Node(4);
    root->lchild->rchild = new Node(5);
    root->rchild->lchild = new Node(6);
    //root->rchild->rchild = new Node(7);

    cout<<leafNodes(root)<<endl;

    return 0;
}