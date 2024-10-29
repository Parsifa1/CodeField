#include<bits/stdc++.h>
using namespace std;

int a[3104],b[3104],i,n,m,ans;

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        b[0]=0;
        b[1]=a[0];
    b[i+1]=a[i]+b[i];
    }
    ans=b[m]-b[0];
    for(int j=1;j<=n-m;j++) {
        ans=min(ans,b[j+m]-b[j]);
    }
    cout<<ans<<endl;
    return 0;
}