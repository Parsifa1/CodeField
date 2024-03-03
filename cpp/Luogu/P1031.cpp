#include<bits/stdc++.h>
using namespace std;
int num[101],all,ans;

int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>num[i];
        all+=num[i];
    }
    all/=n;
    for(int j=1;j<n;j++) {
        if(num[j]<all) {
            num[j+1]=num[j+1]-(all-num[j]);
            num[j]=all;
            ans++;
        }
        if(num[j]==all)
            continue;
        if(num[j]>all) {
            num[j+1]=num[j+1]+(num[j]-all);
            num[j]=all;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}