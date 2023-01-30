#include<bits/stdc++.h>
using namespace std;
int main() {
    double k;
    double n;
    double dd=0.0;

    cin>>k;
    for(n=1.0;;n++) {
        double down =1.0/n;
        dd+=down;
        if(dd>k) {
            cout<<n;
            return 0;
        }
    }
}