#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
    Node *frontNode=NULL,*rearNode=NULL;
public:
    void enqueue(int x){
        Node* temp=new Node();
        temp->data=x;
        temp->next=NULL;
        if(rearNode==NULL){
            frontNode=rearNode=temp;
        } else {
            rearNode->next=temp;
            rearNode=temp;
        }
    }
    void dequeue(){
        if(frontNode){
            Node* temp=frontNode;
            frontNode=frontNode->next;
            if(frontNode==NULL) rearNode=NULL;
            delete temp;
        }
    }
    void front(){
        if(frontNode) cout<<frontNode->data<<endl;
    }
    void empty(){
        cout<<(frontNode==NULL?"Empty":"Not Empty")<<endl;
    }
};

int main(){
    Queue q;
    int n,x;
    cin>>n;
    while(n--){
        int op; cin>>op;
        if(op==1){cin>>x; q.enqueue(x);}
        else if(op==2) q.dequeue();
        else if(op==3) q.front();
        else if(op==4) q.empty();
    }
}
