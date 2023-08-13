#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a[25005];
void solve() {
    int n, ans = 0, minn = 1e9, minm = 1e9; cin >> n;
    
    for(int i = 0; i < n; i++) {
        int m; cin >> m; a[i].resize(m);
        for(auto &x : a[i]) cin >> x;
    }
    if(n == 1) {
        cout << *min_element(a[0].begin(), a[0].end()) << endl;
        return;
    }
    vector<pair<int, int>> minx(n);
    for(int i = 0; i < n; i++) {
        minx[i].first = *min_element(a[i].begin(), a[i].end());
        minn = min(minx[i].first, minn);
        nth_element(a[i].begin(), a[i].begin() + 1, a[i].end());
        minx[i].second = a[i][1];
        minm = min(minx[i].second, minm);
        ans += minx[i].second;
    }
    ans -= (minm - minn);
    cout << ans << endl;
}

signed   main() {
    int T; cin >> T;
    while (T--) solve();
}