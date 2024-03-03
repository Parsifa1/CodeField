#include<bits/stdc++.h>
using namespace std;
int m,n,arr[1000002];

int find(int q) {
    int l=1,r=n;
    while(l<r) {
        int mid = l+(r-l)/2;
        if(arr[mid]>=q)
            r = mid;
        else if(arr[mid]<q)
            l = mid+1;
    }
    if(arr[l]==q) 
        return l;
    else 
        return -1;
    
}

int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>arr[i];
    }
    while(m--) {
        int x; cin>>x;
        int ans=find(x);
        cout<<ans<<" ";
    }
    return 0;
}``