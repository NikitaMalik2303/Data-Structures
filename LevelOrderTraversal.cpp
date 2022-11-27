#include <iostream>
#include <queue>
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

void levelOrder(Node* root){
    queue <Node*> q;
    if(root==NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        root = q.front();
        cout<<root->data<<"  ";
        q.pop();
        if(root->lchild){
            q.push(root->lchild);
        }
        if(root->rchild){
            q.push(root->rchild);
        }
    }
}


int main(){

    Node *root = new Node(50);
    root->lchild = new Node(40);
    root->rchild = new Node(80);
    root->lchild->lchild = new Node(30);
    root->lchild->rchild = new Node(45);
    root->rchild->lchild = new Node(60);
    root->rchild->rchild = new Node(90);

    levelOrder(root);

    return 0;
}