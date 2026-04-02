#include <iostream>
using namespace std;

int main(){
    int q[100], front=-1, rear=-1;
    int n, choice, item;

    cin>>n;

    while(true){
        cin>>choice;

        if(choice==1){
            cin>>item;
            if(rear==n-1) cout<<"Overflow\n";
            else{
                if(front==-1) front=0;
                q[++rear]=item;
            }
        }
        else if(choice==2){
            if(front==-1 || front>rear) cout<<"Underflow\n";
            else{
                cout<<q[front]<<endl;
                front++;
            }
        }
        else{
            break;
        }
    }
}
