#include <bits/stdc++.h>
using namespace std;
// #define int long long
void solve() {
    string s; cin >> s;
    int n = s.length();
    if(s == "()") {
        cout << "NO" << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        int mid = i;
        while(s[mid + 1] == s[i]) {
            mid++;
        }
        if (mid != i) {
            cout << "YES" << "\n";
            for(int i = 0; i < n; i++) {
                cout << "()";
            }
            cout << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; i++) {
        cout << "(";
    }
    for (int i = 0; i < n; i++) {
        cout << ")";
    }
    cout << "\n";
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
}