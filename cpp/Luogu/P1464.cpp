#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rpt[25][25][25];
ll w(ll a,ll b,ll c) {
    if(a<=0||b<=0||c<=0) 
        return 1;
    else if(a>20||b>20||c>20)
        return w(20,20,20);
    else if(rpt[a][b][c]!=0)
        return rpt[a][b][c];
    else if(a<b&&b<c)
        return rpt[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else
        return rpt[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main() {
    ll a,b,c;
    while(cin>>a>>b>>c) {
        if(a==-1&&b==-1&&c==-1)
            break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
    }
    return 0;
}