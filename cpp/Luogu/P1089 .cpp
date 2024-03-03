#include<bits/stdc++.h>
using namespace std;
int all[13],m=300;
int main() {
    for(int i=1;i<=12;i++) {
        cin>>all[i];
    }
    int ans=0,mid=0;
    for(int i=1;i<=12;i++) {
        m=mid+300;
        while(m-all[i]>=100) {
            ans+=100;
            m-=100;
        }
        mid=m-all[i];
        if(m<all[i]) {
            cout<<-i;
            return 0;
        }
        //else    
            //
    }
    cout<<(int)ans*1.2+mid;
}