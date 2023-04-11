#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    /*
    if(n%2!=0) {
        for(int i=1;i<=n;i++) {
            cout<<1<<" ";
        }
        cout<<endl;
    }
    if(n%2==0) {
        for(int i=1;i<n;i++) {
            cout<<2<<" ";
        }
        cout<<1<<endl;
    }
    */
   if(n==1) {
    cout<<1<<endl;
   }
   if(n==2) {
    cout<<1<<" "<<3<<endl;
   }
    if(n>2) {
        cout<<1<<" ";
    for(int i=1;i<n;i++) {
        cout<<n+1<<" ";
    }
    cout<<endl;
    
    }
} 

int main() {
    int T; cin>>T;
    while(T--) {
        solve();
    }
}

