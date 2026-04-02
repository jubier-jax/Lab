#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev,*next;
};

Node* insert(Node* head,int x){
    Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(!head) return temp;
    Node* cur=head;
    while(cur->next) cur=cur->next;
    cur->next=temp;
    temp->prev=cur;
    return head;
}

Node* removeDuplicate(Node* head){
    unordered_set<int> s;
    Node* cur=head;
    while(cur){
        if(s.count(cur->data)){
            Node* del=cur;
            if(cur->prev) cur->prev->next=cur->next;
            if(cur->next) cur->next->prev=cur->prev;
            if(cur==head) head=cur->next;
            cur=cur->next;
            delete del;
        } else {
            s.insert(cur->data);
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
