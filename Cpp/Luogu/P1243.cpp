#include<bits/stdc++.h>
using namespace std;

double x,a=2,ans;
int i;
int main() {
    cin>>x;
    for(i=1;;i++) {
        ans+=a;
        a=a*0.98;
        if(ans>=x) {
            break;
        }
    }
    cout<<i;
}