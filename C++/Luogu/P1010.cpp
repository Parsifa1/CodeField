#include<bits/stdc++.h>
using namespace std;

void search(int n) {
    int s;
    if(n==0)
        return;
    for(int i=0;i<=15;i++) {
        s=i;
        if((1<<s)>n) {
            s--;
            break;
        }
    }
    if(s==0) {
        cout<<"2(0)";
    }
    if(s==1) {
        cout<<"2";
    }
    if(s>1) {
        cout<<"2(";
        search(s);
        cout<<")";
    }
    if(n-(1<<s)!=0) {
        cout<<"+";
        search(n-(1<<s));
    }
}

int main() {
    int n;
    cin>>n;
    search(n);
    return 0;
}