#include<bits/stdc++.h>
using namespace std;
int num[201];

int main() {
     int k=1,ans;
     char mid='0',las='0';
    while(cin>>mid) {
        ans++;
        if(mid==las) {
            num[k]++;
        }
        else {
            num[++k]++;
            
            las=mid;
        }
    }
        cout<<sqrt(ans);
        for(int j=1;j<=k;j++) {
            cout<<" "<<num[j];
        }

}
