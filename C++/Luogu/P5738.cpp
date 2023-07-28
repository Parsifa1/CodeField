#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
double p[101];
int num[1014];
int n;
double ans;
double as() {
    ans=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    for(int j=1;j<n-1;j++) {
        ans+=num[j];
    }
    ans/=n-2;
    return ans;
}

int main() {
    int m;cin>>m>>n;
    for(int i=0;i<m;i++) {
        p[i]=as();
        //printf("%.2lf\n",p[i]);
    }
    sort(p,p+m);
    printf("%.2lf",p[m-1]);
}