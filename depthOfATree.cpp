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

int depth(Node* root){
   if(root==NULL){
        return 0;
   }
   int left = depth(root->lchild);
   int right = depth(root->rchild);
   if(left>right){
        return depth(root->lchild) +1;
   }
   else{
        return depth(root->rchild )+1;
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

    cout<<depth(root);

    return 0;
}