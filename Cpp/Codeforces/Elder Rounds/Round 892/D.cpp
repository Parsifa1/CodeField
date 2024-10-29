#include <bits/stdc++.h>
using namespace std;
using lll = __int128_t;
using ll = long long;
const int N = 2e5 + 5;

void solve() {
    int n; cin >> n;
    vector<array<int, 4>>arr(n);
    for (auto &[l, r, a, b] : arr) cin >> l >> r >> a >> b;
    sort(arr.begin(), arr.end());
    int q; cin >> q;
    vector<array<int, 2>> p(q); 
    for(auto i = 0; i < q; i++) {
        auto &[x, id] = p[i];
        cin >> x;
        id = i;
    }
    sort(p.begin(), p.end());
    int i = 0, mid = 0;
    vector<int> ans(q);
    for (auto [x, id] : p) {
        while (x >= arr[i][0] && i < arr.size()) {
            mid = max(mid, arr[i][3]);
            x = max(mid, x);
            i++;
        }
        ans[id] = max(mid, x);
    }
    for(auto x : ans) cout << x << " ";
    cout << " \n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
