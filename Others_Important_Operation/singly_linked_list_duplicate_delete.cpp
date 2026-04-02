#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insert(Node* head,int x){
    Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(!head) return temp;
    Node* cur=head;
    while(cur->next) cur=cur->next;
    cur->next=temp;
    return head;
}

Node* removeDuplicate(Node* head){
    unordered_set<int> s;
    Node *cur=head,*prev=NULL;
    while(cur){
        if(s.count(cur->data)){
            prev->next=cur->next;
            delete cur;
            cur=prev->next;
        } else {
            s.insert(cur->data);
            prev=cur;
            cur=cur->next;
        }
    }
    return head;
}

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    int n,x;
    cin>>n;
    Node* head=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    head=removeDuplicate(head);
    print(head);
}
