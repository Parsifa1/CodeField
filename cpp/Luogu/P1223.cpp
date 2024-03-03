#include<bits/stdc++.h>
using namespace std;

struct node {
    int s,t;
}a[1000005];
int n; double ans,mid;

bool cmp(node a,node b) {
    return a.t<b.t;
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].t;
        a[i].s = i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i <= n;i++) {
        mid+=a[i-1].t;
        ans+=mid;
        cout<<a[i].s<<" ";
    }
    cout<<endl;
    ans/=n;
    printf("%.2lf",ans);
}