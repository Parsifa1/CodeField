#include<bits/stdc++.h>
using namespace std;
string s = "abcdefghijklmnopqrstuvwxyz";
void solve() {
    int n,ans=0; cin>>n;
    char c = 'a';
    for(int i=0;i<n;i++) {
        cin>>c;
        for(int j=1;j<=26;j++) {
            if(c==s[j-1]) {
                ans=max(ans,j);
            }
        }
    }
    cout<<ans<<endl;
}
int main() {
    int T; cin>>T;
    while(T--) {
        solve();
    }
}