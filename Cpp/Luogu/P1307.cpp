#include<bits/stdc++.h>
using namespace std;


int solve() {
    int n;
    cin>>n;
    int tem=0;
    for(int i=0;;i++) {    
        tem=10*tem+n%10;
        n/=10;                
        if(n==0) {
            cout<<tem<<endl;
            return 0;
        }  
    }
}



int main() {
    solve();
}