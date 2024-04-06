#include <bits/stdc++.h>
// #define int long long
using namespace std;
int a[21];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    auto [mn, mx] = minmax_element(a + 1, a + 1 + n);
    // cerr << *mn << " " << *mx << endl;
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    if(*mx <= 0 && *mn <= 0) {
        cout << n - 1 << endl;
        for(int i = n; i > 1; i--) {
            cout << i - 1 << " " << i << endl;
        }
        return;
    } else {
        cout << 7 + 2 + 2 * (n - 2) << endl;
        int k = mx - a;
        for(auto i = 1; i <= 6; i++) {
            cout << k << " " << k << endl;
        }
        cout << 2 << " " << k << endl;
        cout << 2 << " " << k << endl;
        cout << 2 << " " << k << endl;
        for(int i = 2; i < n; i++) {
            cout << i + 1 << " " << i << endl;
            cout << i + 1 << " " << i << endl;
        }
        return;
    }
}

signed main() {
    init();
    int T; cin >> T;
    while(T--) solve();
}