#include<bits/stdc++.h>
using namespace std;

int k,coin,flag1,flag2,ans,all;
int main() {
    cin>>k;
    for(int i=1;;i++) {
        flag1=i*(i+1)/2;
        flag2=(i-1)*1/2;
        all+=i*i;
        if(k<=flag1&&k>=flag2) {
            ans=all-(flag1-k)*i;
            cout<<ans;
            return 0;
        }
        
    }
}