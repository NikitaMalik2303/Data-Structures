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

bool parentNoRoot(Node* root,int key){
    int flag =0;
    if(root->lchild!=NULL){
        if(root->lchild->data == key){
            cout<<"The parent of the given node is "<<root->data<<endl;
            flag =1;
            return true;
        }
        else{
            parentNoRoot(root->lchild , key);                                          
        }
    }
    if (root->rchild!=NULL){
        if(root->rchild->data == key){
            cout<<"The parent of the given node is "<<root->data<<endl;
            flag =1;
            return true;
        }
        else{
            parentNoRoot(root->rchild,key);
        }
    }
    if(flag ==0){
        return false;
    }
}

void parent(Node* root,int key){
    if(root->data==key){
        cout<<"Root elemnet does not have parent"<<endl;
        return;
    }
    else{
        if(!parentNoRoot(root,key)){
            cout<<"The given element is not present in the binary tree"<<endl;
        }
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

    int key;
    cin>>key;

    parent(root,key);

    return 0;
}