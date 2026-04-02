#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    vector<int> v;
public:
    void insert(int x){
        v.push_back(x);
        int i=v.size()-1;
        while(i>0 && v[(i-1)/2]>v[i]){
            swap(v[i],v[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    void deleteRoot(){
        if(v.empty()) return;
        v[0]=v.back();
        v.pop_back();
        int i=0,n=v.size();
        while(true){
            int l=2*i+1,r=2*i+2,smallest=i;
            if(l<n && v[l]<v[smallest]) smallest=l;
            if(r<n && v[r]<v[smallest]) smallest=r;
            if(smallest!=i){
                swap(v[i],v[smallest]);
                i=smallest;
            } else break;
        }
    }
    void getMin(){
        if(!v.empty()) cout<<v[0]<<endl;
    }
};

int main(){
    MinHeap h;
    int n,x;
    cin>>n;
    while(n--){
        int op; cin>>op;
        if(op==1){cin>>x; h.insert(x);}
        else if(op==2) h.deleteRoot();
        else if(op==3) h.getMin();
    }
}
