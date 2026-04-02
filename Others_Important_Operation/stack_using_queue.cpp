#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if(!q.empty()) q.pop();
    }
    void top() {
        if(!q.empty()) cout<<q.front()<<endl;
    }
    void empty() {
        cout<<(q.empty()?"Empty":"Not Empty")<<endl;
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
