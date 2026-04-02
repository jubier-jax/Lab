#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    Node* topNode=NULL;
public:
    void push(int x){
        Node* temp=new Node();
        temp->data=x;
        temp->next=topNode;
        topNode=temp;
    }
    void pop(){
        if(topNode){
            Node* temp=topNode;
            topNode=topNode->next;
            delete temp;
        }
    }
    void top(){
        if(topNode) cout<<topNode->data<<endl;
    }
    void empty(){
        cout<<(topNode==NULL?"Empty":"Not Empty")<<endl;
    }
};

int main(){
    Stack s;
    int n,x;
    cin>>n;
    while(n--){
        int op; cin>>op;
        if(op==1){cin>>x; s.push(x);}
        else if(op==2) s.pop();
        else if(op==3) s.top();
        else if(op==4) s.empty();
    }
}
