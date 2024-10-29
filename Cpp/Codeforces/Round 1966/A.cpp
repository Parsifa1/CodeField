#include <iostream>
#include <vector>
using i64 = long long;
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> c(n), d(101);
    for (int &x : c) std::cin >> x;
    for (int x : c) d[x]++;
    for (int i = 1; i <= 100; i++) {
        if (d[i] >= k) {
            std::cout << k - 1 << '\n';
            return;
        }
    }
    std::cout << n << '\n';
}
signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) solve();
}
