#include <iostream>
using namespace std;

/*          50
           /   \
         40     80
        / \     / \
       30  45  60  90
*/

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

void insert(Node* root, int elem){
    Node* prev = NULL;
    Node* curr = root;
    if(curr == NULL){
        Node* temp = new Node(elem);
        root = temp;
        return;
    }
    while(curr!=NULL){
        if(elem>curr->data){
        prev = curr;
        curr = curr->rchild;
    }
    else if(elem<curr->data){
        prev = curr;
        curr = curr->lchild;
    }
    else{
        cout<<"Not possible to insert the given element in BST"<<endl;
        return;
    }
    }
    
    if(prev->data>elem){
        prev->lchild = new Node(elem);
    }
    else{
        prev->rchild = new Node(elem);
    }
}

void preorder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<"  ";
    preorder(root->lchild);
    preorder(root->rchild);
}

int main(){

    Node *root = new Node(50);
    root->lchild = new Node(40);
    root->rchild = new Node(80);
    root->lchild->lchild = new Node(30);
    root->lchild->rchild = new Node(45);
    root->rchild->lchild = new Node(60);
    root->rchild->rchild = new Node(90);

    preorder(root);

    cout<<endl;

    int elem;
    cin>>elem;

    insert(root,elem);

    preorder(root);

    return 0;
}