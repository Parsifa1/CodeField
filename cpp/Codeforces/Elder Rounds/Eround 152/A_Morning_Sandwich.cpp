#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int b, c, h;
    cin >> b >> c >> h;
    int res = c + h;
    if (res + 1 > b)
        cout << (b - 1) * 2 + 1 << endl;
    else if (res + 1 < b)
        cout << res * 2 + 1 << endl;
    else
        cout << (b - 1) * 2 + 1 << endl;
}
signed main() {
    init();
    int T;
    cin >> T;
    while (T--) solve();
}
