#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    int ans=0;
    for(int i=n;i>=1;i--) {
        int t=1;
        ans+=t*i;
        t++;
    }
    for(int j=n;j>=1;j--) {
        int t=n+1;
        ans+=t*j;
        t--;
    }
    cout<<ans;
}
