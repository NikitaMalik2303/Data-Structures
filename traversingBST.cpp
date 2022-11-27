#include <iostream>
using namespace std;

#define space 5

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

void print(Node* root, int level){
    if(root == NULL){
        return;
    }
    level+=space;
    print(root->rchild, level);
    for(int i =space; i<level;i++){
        cout<<"  ";
    }
    cout<<root->data<<endl;
    print(root->lchild, level);
}

void preorder(Node* root){
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

    print(root,0);

    return 0;
}