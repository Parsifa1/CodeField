#include<bits/stdc++.h>
using namespace std;
int a[1140],f[1140];
void pre(int n) {
    for(int i=0;i<n;i++) {
        a[i]=i;
    }
    for(int i=0;i<n;i++) {
        f[0]=a[0];
    f[i]=a[i]+f[i-1];
    }
}
void solve() {
    int m,s,ans=0; 
    int b[51];
    cin>>m>>s;
    for(int i=0;i<m;i++) {
        cin>>b[i];
        ans+=b[i];
    }
    sort(b,b+m);
    pre(b[m-1]+100);
    for(int j=0;j<b[m-1]+100;j++) {

        if(f[j]-ans==s) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
      int T; cin>>T;
    while(T--) {
        solve();
    }
    
}