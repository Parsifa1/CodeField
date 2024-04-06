#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6 + 5;

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<int> s(m + 2);

    for (int i = 1; i <= m; i++) {
        cin >> s[i];
    }
    s[0] = 1 - d, s[m + 1] = n + 1;
    // for(auto x : s) cerr << x << " ";
    // cerr << "\n";
    int sum = m;
    for(int i = 1; i <= m + 1; i++) {
        sum += (s[i] - s[i - 1] - 1 ) / d;
    }
    // cerr << sum << endl;
    int minx = n + 1, cnt = 0;
    for (int i = 1; i <= m; i++) {
        int res = sum;
        res += (s[i + 1] - s[i - 1] - 1) / d;
        res -= (s[i] - s[i - 1] - 1) / d;
        res -= (s[i + 1] - s[i] - 1) / d;
        res--;
        if(res == minx) cnt++;
        if(res < minx){
            cnt = 1;
            minx = res;
        }
    }
    
    cout << minx << " " << cnt << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
}
