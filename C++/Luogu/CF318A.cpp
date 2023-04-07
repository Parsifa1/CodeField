#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
int main() {
    cin>>n>>k;
    //for(ll i=1;i<=n;i++) {
        if(n&1) {
            if(k<=(n+1)/2) {
                cout<<2*k-1;
            }
            else {
                cout<<2*(k-(n+1)/2);
            }
        }
        else {
            if(k<=n/2) {
                cout<<2*k-1;
            }
            else {
                cout<<2*(k-n/2);
            }
        }
    //}
}