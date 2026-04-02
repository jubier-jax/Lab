#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* insertAtPos(Node* head, int pos, int val) {
    Node* newNode = new Node{val, NULL, NULL};

    if(pos == 0) {
        newNode->next = head;
        if(head != NULL)
            head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    for(int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
        return head;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* temp = new Node{x, NULL, NULL};
        if(head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    int pos, val;
    cin >> pos >> val;

    head = insertAtPos(head, pos, val);
    printList(head);
}
