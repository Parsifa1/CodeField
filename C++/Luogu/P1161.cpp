#include<bits/stdc++.h>
using namespace std;
bool lap[2000001]={0};
double p,q;
int main() {
    int n; cin>>n;
    int temp=0;
    for(int i=1;i<=n;i++) {
        cin>>p>>q;
        for(double j=1;j<=q;j++) {
            temp =(int)(p*j);
            if(lap[temp]) 
                lap[temp]=0;
            else 
                lap[temp]=1;
        }  
    }
    for(int i=1;i<2000001;i++) {
        if(lap[i]) {
            cout<<i;
            return 0;
        }
    }
}