#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int solve() {
    int n=0;
    cin>>n;
    num[1]=1;
    cout<<2<<endl;
    for(int i=1;i<=n;i+=2) {
        for(int j=i;j<=n;j<<=1)
            cout<<j<<' ';
    }
    cout<<endl;
    return 0;
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}