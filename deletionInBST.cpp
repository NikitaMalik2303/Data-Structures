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

void deleteNode(Node* root, int key){
    if(root == NULL){
        return;
    }
    Node* prev,*curr = NULL;
    Node* temp = root;

    while(temp!=NULL){
        if(temp->data == key){
            curr = temp;
            break;
        }
        prev = temp;
        if(key < temp->data){
            temp = temp->lchild;
        }
        else if(key > temp->data){
            temp = temp->rchild;
        }

    }
    
    if(curr->lchild == NULL && curr->rchild == NULL){
        if(prev->lchild == curr){
            prev->lchild = NULL;
        }
        if(prev->rchild == curr){
            prev->rchild = NULL;
        }
        delete (curr);
        return;
    }

    if(curr->lchild!=NULL && curr->rchild == NULL){
        if(prev->lchild == curr){
            prev->lchild = curr->lchild;
        }
        if(prev->rchild == curr){
            prev->rchild = curr->lchild;
        }
        delete (curr);
        return;
    }

    if(curr->rchild != NULL && curr->lchild == NULL){
        if(prev->lchild == curr){
            prev->lchild = curr->rchild;
        }
        if(prev->rchild == curr){
            prev->rchild = curr->rchild;
        }
        delete (curr);
        return;
    }

    if(curr->lchild !=NULL && curr->rchild!=NULL){
        Node* succ = curr->rchild;
        prev = curr;
        while(succ->lchild!=NULL){
            prev = succ;
            succ = succ->lchild;
        }
        int val = succ->data;
        deleteNode(root,val);
        curr->data = val;
        
        return;
    }

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

    Node *root = new Node(50);
    root->lchild = new Node(40);
    root->rchild = new Node(80);
    root->lchild->lchild = new Node(30);
    root->lchild->rchild = new Node(45);
    root->rchild->lchild = new Node(60);
    root->rchild->rchild = new Node(90);

    cout<<"Enter the element"<<endl;
    int key;
    cin>>key;

    cout<<"The tree before deleting"<<endl;
    inorder(root);

    cout<<"Deleting..."<<endl;

    deleteNode(root,key);

    cout<<"The tree after deleting the node..."<<endl;

    inorder(root);

    return 0;
}