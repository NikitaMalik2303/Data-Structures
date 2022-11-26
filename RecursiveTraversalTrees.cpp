#include <iostream>
using namespace std;

/*          1
           / \
         2     3
        / \   / \
       4   5  6  7 
*/

class Node {
    public:
    int data;
    Node* lchild;
    Node* rchild;
    Node(int n){
        data = n;
        lchild = NULL;
        rchild = NULL;
    }
};

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->lchild);
    cout<<root->data<<"  ";
    inorder(root->rchild);
}

void preorder(Node *root){
    if(root == NULL){
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

int main(){
     
    Node *root = new Node(1);
    root->lchild = new Node(2);
    root->rchild = new Node(3);
    root->lchild->lchild = new Node(4);
    root->lchild->rchild = new Node(5);
    root->rchild->lchild = new Node(6);
    root->rchild->rchild = new Node(7);

    cout<<"Inorder Traversal"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Preorder Traversal"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Postorder Traversal"<<endl;
    postorder(root);
    cout<<endl;

    return 0;
}