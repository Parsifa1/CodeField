#include <bits/stdc++.h>
using namespace std;
using lll = __int128_t;
using ll = long long;
vector<int> a, b, ans;
vector<pair<int, int>> c;

void solve() {
    int n, cnt = 0; cin >> n;
    a.resize(n + 1), b.resize(n + 1),c.resize(n);
    ans.clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        c[i] = {a[i + 1] - b[i + 1], i + 1};
    }
    sort(c.begin(), c.end(), [](auto x, auto y) {
        if(x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    });
    auto [maxx, id] = c[0];
    for(int i = 0; i < n; i++) {
        if(c[i].first == maxx) {
            cnt++;
            ans.push_back(c[i].second);
        }
        else break;
    }
    cout << cnt << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
