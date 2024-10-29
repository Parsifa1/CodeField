#include<bits/stdc++.h>
using namespace std;
int num[11451],dp[11451],n,maxx;
int main() {
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    for(int j=1;j<=n;j++) {
        
        if(num[j]+1==num[j+1]) {
            dp[j+1]=dp[j]+1;      
        }
        maxx=max(maxx,dp[j+1]); 
    }
    cout<<maxx<<endl;
} 