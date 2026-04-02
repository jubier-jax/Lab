#include <iostream>
using namespace std;

int binarySearch(int a[], int lb, int ub, int item, int &loc){
    while(lb<=ub){
        int mid=(lb+ub)/2;
        if(a[mid]==item){
            loc=mid;
            return 1;
        }
        else if(a[mid]<item) lb=mid+1;
        else ub=mid-1;
    }
    loc=lb;
    return 0;
}

int main(){
    int n,item,loc;
    cin>>n;
    int a[100];

    for(int i=0;i<n;i++) cin>>a[i];
    cin>>item;

    int found=binarySearch(a,0,n-1,item,loc);

    if(!found){
        for(int i=n;i>loc;i--) a[i]=a[i-1];
        a[loc]=item;
        n++;
    }

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
