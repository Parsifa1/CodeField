#include<bits/stdc++.h>
using namespace std;
int x,k,n;
int main() {
    cin>>n;
    while(++k) {
        if(n%364==0) {
            x=(n/364)-3*k;
        }
        if(x<=100)
            break;
    }
    cout<<x<<"\n"<<k;
} 