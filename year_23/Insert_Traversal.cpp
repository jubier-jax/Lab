#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(int val){
    Node* temp=new Node();
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

Node* insert(Node* root,int val){
    if(root==NULL) return create(val);
    if(val<root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    Node* root=NULL;
    int n,x;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        root=insert(root,x);
    }

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}
