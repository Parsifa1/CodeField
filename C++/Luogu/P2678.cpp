#include<bits/stdc++.h>
using namespace std;
int L,n,m,num[50011],ans;

bool check(int x) {
    int tot=0,aft=0;
    for(int i=1;i<=n+1;i++) {
        if(num[i]-num[aft]<x)
            tot++;
        else    
            aft=i;
    }
    if(tot>m)
        return false;
    else 
        return true;
}

int main() {
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>num[i];
    }
    num[n+1]=L;
    int l=1,r=L;
    while(l<=r) {
        int mid=(l+r)/2;
        if(check(mid)) {
            l=mid+1;
            ans=mid;
        } else {
            r=mid-1;
        } 
    }
    cout<<ans<<endl;
    return 0;
}