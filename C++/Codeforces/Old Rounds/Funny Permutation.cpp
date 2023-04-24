#include<bits/stdc++.h>
using namespace std;


int solve() {
    int n=0;
    cin>>n;
    if(n!=3&&n!=2) {
        cout<<n-1<<" "<<n<<" ";
        for(int i=1;i<n-1;i++) {
            cout<<i<<" ";
        }
    }
    else if(n==3)
        cout<<-1<<" ";
    else if(n==2)
        cout<<2<<" "<<1<<" ";
    return 0;
    
}
int main() {
    int t;
    cin>>t;
    for(int j=0;j<t;j++) {
        solve(); 
    }
    return 0;
}