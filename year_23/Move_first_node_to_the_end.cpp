#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insertEnd(Node* start, int x){
    Node* newNode=new Node();
    newNode->data=x;
    newNode->next=NULL;

    if(start==NULL) return newNode;

    Node* temp=start;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;

    return start;
}

Node* moveFirstToEnd(Node* start){
    if(start==NULL || start->next==NULL) return start;

    Node* first=start;
    start=start->next;
    first->next=NULL;

    Node* temp=start;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=first;

    return start;
}

void printList(Node* start){
    while(start!=NULL){
        cout<<start->data<<" ";
        start=start->next;
    }
}

int main(){
    int n,x;
    cin>>n;

    Node* start=NULL;

    for(int i=0;i<n;i++){
        cin>>x;
        start=insertEnd(start,x);
    }

    start=moveFirstToEnd(start);

    printList(start);
}
