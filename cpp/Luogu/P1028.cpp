#include<bits/stdc++.h>
using namespace std;
int num[1016];
int main() {
    int n; cin>>n;
    num[1]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i/2;j++) {
            num[i]+=num[j];
        }
        num[i]++;
    }
    cout<<num[n];
    return 0;



}