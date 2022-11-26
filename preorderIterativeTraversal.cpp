#include <iostream>
#include <stack>
using namespace std;

/*          1
           / \
         2     3
        / \   / \
       4   5  6  7 
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

void preorder(Node* root){
    stack <Node*> s;
    while(true){
        for(;root!=NULL ; root=root->lchild){
            s.push(root);
            cout<<root->data<<"  ";
        }
        root = s.top();
        s.pop();
        if(root == NULL){
            return;
        }
        root = root->rchild;
    }
}

int main(){

    Node *root = new Node(1);
    root->lchild = new Node(2);
    root->rchild = new Node(3);
    root->lchild->lchild = new Node(4);
    root->lchild->rchild = new Node(5);
    root->rchild->lchild = new Node(6);
    root->rchild->rchild = new Node(7);

    preorder(root);




}