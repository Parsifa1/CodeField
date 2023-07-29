#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
pair<int, int> p[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i].first, p[i].second = i;
    int res = 0;
    for(int i = 1; i <= n; i++) if(p[i].first == p[i].second) res++;
    if(res % 2 != 0) cout << (res / 2) + 1 << endl;
    else if(res % 2 == 0) cout << res / 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}