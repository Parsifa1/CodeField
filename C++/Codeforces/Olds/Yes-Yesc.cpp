#include<bits/stdc++.h>
using namespace std;
void solve() {
    string s; cin>>s;
    string a = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
    int len = s.length();
    for(int i=0;i<=52-len;i++) {
        if(s == a.substr(i,len)) {
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