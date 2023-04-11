#include<bits/stdc++.h>
using namespace std;
struct node {
    int ch,ma,en;
    int ans;
}stu[1001];

bool dcd(node x,node y) {
    int da,db,dc,dn;
    da=abs(x.ch-y.ch);
    db=abs(x.ma-y.ma);
    dc=abs(x.en-y.en);
    dn=abs(x.ans-y.ans);
    if(da<=5&&db<=5&&dc<=5&&dn<=10)
        return true;
    else
        return false;
    
}



int main() {
    int n,p=0; cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>stu[i].ch>>stu[i].ma>>stu[i].en;
            stu[i].ans=stu[i].ch+stu[i].ma+stu[i].en;
        }
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(dcd(stu[i],stu[j])) {
                    p++;
                }
            }
        }
        cout<<p;
    return 0;
}