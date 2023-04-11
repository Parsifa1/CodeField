#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
void dfs(int a,int s,int c) {
    if(c==k) {
        if(s==n) {
            cnt++;
        }
        return;
    }
        
    for(int i=a;s+i*(k-c)<=n;i++)
        dfs(i,s+i,c+1);
}
int main() {
    cin>>n>>k;
    dfs(1,0,0);
    cout<<cnt;
}