#include <iostream>
using namespace std;

int stackArr[100];
int top = -1;
int MAX;

void push(int item) {
    if(top == MAX - 1)
        return;
    stackArr[++top] = item;
}

void pop() {
    if(top == -1)
        return;
    top--;
}

void display() {
    for(int i = top; i >= 0; i--)
        cout << stackArr[i] << " ";
}

int main() {
    cin >> MAX;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(x);
    }

    int op;
    cin >> op;

    if(op == 1) {
        int val;
        cin >> val;
        push(val);
    }
    else if(op == 2) {
        pop();
    }

    display();
}
