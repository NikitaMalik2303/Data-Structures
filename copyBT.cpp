#include <iostream>
using namespace std;

#define space 5

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

Node* create(){
    int val;
    cin>>val;
    if(val==-1){
        return NULL;
    }
    Node* temp = new Node(val);
    temp->lchild = create();
    temp->rchild = create();
}

Node* copy(Node* root1){
    if(root1 == NULL){
        return NULL;
    }
    Node* root2 = new Node(root1->data);
    root2->rchild = copy(root1->rchild);
    root2->lchild = copy(root1->lchild);
    return root2;
}

void display(Node* root, int level){
    if(root == NULL){
        return ;
    }
    level += space;
    display(root->rchild,level);
    for(int i = space; i<level; i++){
        cout<<"  ";
    }
    cout<<root->data<<endl;
    display(root->lchild,level);
}

int main(){

    Node* root1 = create();

    cout<<"Tree 1 :"<<endl;
    display(root1,0);

    Node* root2 = copy(root1);
    cout<<"Tree 2 : "<<endl;
    display(root2,0);



    return 0;
}