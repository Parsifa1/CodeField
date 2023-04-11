#include<bits/stdc++.h>
using namespace std;
void solve() {
    int num[4];
    cin>>num[1]>>num[2]>>num[3];
    sort(num+1,num+4);
    cout<<num[2]<<endl;
}

int main() {
    int T; cin>>T;
    while(T--) {
        solve();
    }
}