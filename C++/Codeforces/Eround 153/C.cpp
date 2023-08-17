#include <bits/stdc++.h>
using namespace std;
// #define int long long

vector<int> p;
void solve() {
    int n, ans = 0; cin >> n;
    p.resize(n);
    for(auto &x : p) cin >> x;
    int minx = n + 1, ok = 1, mini = n + 1;
    for(int i = 0; i < n; i++) {
        ok = 1;
        if(p[i] < minx) {
            minx = p[i];
            ok = 0;
        } else {
            if(p[i] < mini) ok = 1;
            else ok = 0;
        }
        if(ok) {
            ans++;
            mini = min(mini, p[i]);
        }
    }
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
} 