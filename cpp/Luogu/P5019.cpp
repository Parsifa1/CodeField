#include<bits/stdc++.h>
using namespace std;
int num[100001];

int main() {
    int n; cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>num[i];
    }
    
    int ans = 0;
    for(int i=2;i<=n;i++) {
        if(num[i]>num[i-1]) {
            ans+=num[i]-num[i-1];
        }
       
    }
    cout<<ans+num[1];

}