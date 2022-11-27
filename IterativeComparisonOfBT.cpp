#include <iostream>
#include <queue>
using namespace std;

# define space 5

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

bool compare(Node* root1, Node* root2){
    if(!root1 && !root2){
        return true;
    }
    queue <Node*> q1;
    queue <Node*> q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() && !q2.empty()){
        Node* n1 = q1.front();
        Node* n2 = q2.front();
        q1.pop();
        q2.pop();
        if(n1->data != n2->data){
            return false;
        }
        if(n1->lchild && n2->lchild){
            q1.push(n1->lchild);
            q2.push(n2->lchild);
        }
        if(n1->rchild && n2->rchild){
            q1.push(n1->rchild);
            q2.push(n2->rchild);
        }
        if(n1->lchild || n2->lchild){
            return false;
        }
        if(n1->rchild || n2->rchild){
            return false;
        }
    }
}

void preorder(Node * root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<"  ";
    preorder(root->lchild);
    preorder(root->rchild);
}

void print(Node* root, int level){
    if(root == NULL){
        return;
    }
    level += space;
    print(root->rchild, level);
    for(int i =space;i<level;i++){
        cout<<"  ";
    }
    cout<<root->data<<endl;
    print(root->lchild, level);
}

int main(){

    // Node *root = new Node(50);
    // root->lchild = new Node(40);
    // root->rchild = new Node(80);
    // root->lchild->lchild = new Node(30);
    // root->lchild->rchild = new Node(45);
    // root->rchild->lchild = new Node(60);
    // root->rchild->rchild = new Node(90);

    cout<<"First tree"<<endl;
    Node* root1 = create();
    print(root1,0);

    cout<<"Second tree"<<endl;
    Node* root2 = create();
    print(root2,0);

    if(compare(root1,root2)){
        cout<<"Both the trees are equal"<<endl;
    }
    else{
        cout<<"The given trees are not equal"<<endl;
    }


    return 0;
}