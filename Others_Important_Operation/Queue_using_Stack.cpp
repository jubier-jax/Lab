#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1,s2;
public:
    void enqueue(int x){
        s1.push(x);
    }
    void dequeue(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()) s2.pop();
    }
    void front(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()) cout<<s2.top()<<endl;
    }
    void empty(){
        cout<<((s1.empty()&&s2.empty())?"Empty":"Not Empty")<<endl;
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
