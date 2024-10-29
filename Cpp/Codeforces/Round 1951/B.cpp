#include <iostream>
#include <string>
#include <vector>
using i64 = long long;
using M = std::vector<std::string>;
void solve() {
    int n, m;
    std::cin >> n >> m;
    M a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][0] != a[i][m - 1]) cnt1++;
    }
    for (int i = 0; i < m; i++) {
        if (a[0][i] != a[n - 1][i]) cnt2++;
    }
    if (cnt1 == n || cnt2 == m)
        std::cout << "NO" << '\n';
    else
        std::cout << "YES" << '\n';
}
signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) solve();
}
