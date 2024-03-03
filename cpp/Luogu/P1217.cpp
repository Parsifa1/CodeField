#include<bits/stdc++.h>
using namespace std;

int t,n,a,x,prime[9989900]={0};
bool all[9989900]={0};

bool aa(int x) {
    if(!(x%10)&&x) return false;
    int tem=0;
    for(int i=0;;i++) {    
        tem=10*tem+x%10;
        x/=10;                
        if(x<=tem) {
            return (x==tem||x==tem/10);
        }  
    }
}

int main() {
    cin>>a>>n;
    if(n>9989899)
        n=9989899;
    for(int i=2;i<=n;i++) {
        if(all[i]==0) {
            prime[t++]=i;
        }
        for(int j=0;j<t&&i*prime[j]<=n;j++) {
            all[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
    
    for(int k=0;k<t;k++) {
        if(prime[k]>=a) {
            if(aa(prime[k])==1) {
                cout<<prime[k]<<endl;
            }   
        }          
    }
    return 0;
}
