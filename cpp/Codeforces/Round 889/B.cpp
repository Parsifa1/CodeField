#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long
int n;



void solve() {
    int ans = 0, c = 0, i = 1;
    cin >> n;
    while(i <= pow(n, 0.1)) {
        while(n % i == 0) {
            c++;
            ans = max(ans, c);
            i++;
        }
        i++;
         c = 0;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}