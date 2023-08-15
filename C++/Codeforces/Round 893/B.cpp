#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6 + 5;
map<int, int> mp;
vector<int> s;
void solve() {
    int n, m, d; cin >> n >> m >> d;
    s.resize(m);
    mp.clear();
    for(auto &x : s) {
        cin >> x;
        x--, mp[x]++;
    }
    // vector<int> p(m), q(m);
    // // p.push_back(0);
    // adjacent_difference(s.begin(), s.end(), p.begin());
    // for(auto x : p) cerr << x << " ";
    int cnt = 1, mid = 0;
    for (int i = 1; i < n; i++) {
        if(mp[i] == 1) {
            cnt++;
            mid = i;
            mp[mid + d] = 2;
            cout << mp[mid + d] << endl;
        }

        if(mp[mid + d] && mid + d < n) {
            cnt++;
            mid += d;
        }
    }
    cerr << cnt << "\n";
    // cerr << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
}
