#include<bits/stdc++.h>
using namespace std;
int x[101];
int main() {
    int n=0,t=0,ans=0;
    cin>>n>>t;
    for (int i=n;i>=1;i--) cin>>x[i];
    while(n) {
        if(86400-x[n]>=t) {
            cout<<ans+1;
            return 0;
        }
        else {
            t-=86400-x[n];
            ans++;
            n--;
        }
        
    }
}