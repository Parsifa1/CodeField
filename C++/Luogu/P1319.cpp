#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,st=0;
    cin >> n;
    int mid,s=0;
    for (int i = 1;;i++) {
        if (st == n * n) {
            return 0;
        }
        
        cin >> mid;
        st+=mid;
        
        for(int j=1;j<=mid;j++) {
            if(s==n) {
                cout<<endl;
                s=0;
            }
            if (i % 2) {
                cout<<0;
            } else {
                cout<<1;
            }
            s++;
        }
    }
}