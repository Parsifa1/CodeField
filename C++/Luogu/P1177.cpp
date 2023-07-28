#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
        sort(a,a+n);
    for(int j=0;j<n;j++) {
        printf("%d ",a[j]);
    }
    return 0;
}