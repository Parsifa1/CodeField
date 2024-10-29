#include <bits/stdc++.h>
using namespace std;
using lll = __int128_t;
using ll = long long;


void solve() {
    int n, x, ans = 0; cin >> n;
    int res = 0, maxx = 0;
    for(int x = n; x >= 1; x--) {
        res = 0, maxx = 0;
        for(int i = 1; i < x; i++) {
            res += i * i;
            maxx = max(maxx, i * i);
        }
        int j = n;
        for(int i = x; i <= n; i++) {
            // cout << j << endl;
            res += i * j;
            maxx = max(maxx, i * j);
            j--;
        }   
        // cout << res << " "<< maxx << endl;
    ans = max(ans, res - maxx);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
 