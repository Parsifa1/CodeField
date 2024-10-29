#include <iostream>
#include <vector>
using i64 = long long;
using M = std::vector<std::vector<char>>;
void solve() {
    int n, m;
    std::cin >> n >> m;
    M a(n, std::vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 'B' &&  a[i][m - 1] == 'W') cnt1++;
        if (a[i][0] == 'W' &&  a[i][m - 1] == 'B') cnt2++;
    }
    for (int i = 0; i < m; i++) {
        if (a[0][i] == 'B' && a[n - 1][i] == 'W') cnt3++;
        if (a[0][i] == 'W' && a[n - 1][i] == 'B') cnt4++;
    }
    if (cnt1 == n || cnt2 == n || cnt3 == m || cnt4 == m)
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
