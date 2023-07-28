#include<bits/stdc++.h>
using namespace std;

int n;

int lenL() {
    int k = 2;
    int b = 0;
    while(b<=n) {
            k++;    
            b = b * 2 + k;
    }
    return b;
}
int lenK() {
    int k = 2;
    int b = 0;
    while(b<=n) {
            k++;    
            b = b * 2 + k;
    }
    return k;
}
int search(int l,int k) {
    while(l) {
        l = (l - k) / 2;
            if(l<n) {
                if(n<=l+k) {
                    if(n==l+1) {
                        cout << "m";
                        return 0;
                    }
                    else {
                        cout << "o";
                        return 0;
                    }
                }
                else
                    n = n - l - k;
            }
        k--;
    }
    return 0;
}
int main() {
    cin >> n;
    //cout << lens();
    search(lenL(),lenK());
}
