#include<bits/stdc++.h>
using namespace std;
int pp[300001],n;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>pp[i];
    }
    sort(pp+1,pp+n+1);
    int ans=0,mid=0;
    for(int i=1;i<=n;i++) {
        mid = max(mid,pp[i]+n-i+1);
    }
    
    for(int i=1;i<=n;i++) {
        if(pp[i]+n>=mid)
            ans++;
    }
    cout<<ans;
}