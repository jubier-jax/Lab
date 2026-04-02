#include <iostream>
using namespace std;

int main(){
    int stack[100], top=-1;
    int n, choice, item;

    cin>>n;

    while(true){
        cin>>choice;

        if(choice==1){
            cin>>item;
            if(top==n-1) cout<<"Overflow\n";
            else stack[++top]=item;
        }
        else if(choice==2){
            if(top==-1) cout<<"Underflow\n";
            else{
                cout<<stack[top]<<endl;
                top--;
            }
        }
        else break;
    }
}
