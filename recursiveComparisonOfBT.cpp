#include <iostream>
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
    return root1->data == root2->data && compare(root1->lchild,root2->rchild) && compare(root1->rchild,root2->rchild);
}

int main(){

    cout<<"First tree"<<endl;
    Node* root1 = create();

    cout<<"Second tree"<<endl;
    Node* root2 = create();

    if(compare(root1,root2)){
        cout<<"Both the trees are equal"<<endl;
    }
    else{
        cout<<"The given trees are not equal"<<endl;
    }

    return 0;
}
