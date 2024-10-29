#include<bits/stdc++.h>
using namespace std;

struct node {
    long double x,y;
}a[200009];
double ans=10000000.0;
double dis(double a,double b,double c,double d){
	return sqrt(abs(c-a)*abs(c-a)+abs(d-b)*abs(d-b));
}
 
int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans=min(ans,dis(a[i].x,a[i].y,a[j].x,a[j].y));
    printf("%.4lf",ans);
	return 0;
} 