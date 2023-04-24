#include<bits/stdc++.h>
using namespace std;
#define ll long long


int solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n % 2 != 0) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << n << " ";
        for(int i = 2; i <= n; i++) {
            if(i % 2 != 0) {
                cout << i  - 1 << " ";
            } else {
                cout << n - i + 1 << " ";
            }
        }
    }
    cout << endl;
    return 0;
}



int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}