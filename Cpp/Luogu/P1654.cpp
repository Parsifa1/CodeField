#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 INF = 1e18;
constexpr int mod = 998244353;

i64 f[65], inv[65];
inline auto read() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    return [](auto x) { return std::cin >> x, x; }(0ll);
}

void init() {
    int N = 61;
    f[0] = f[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= N; i++)
        f[i] = (i64)f[i - 1] * i % mod, inv[i] = (i64)(mod - mod / i) * inv[mod % i] % mod;
    for (int i = 1; i <= N; i++) inv[i] = (i64)inv[i - 1] * inv[i] % mod;
}

i64 C(int m, int n) {
    if (n < m || m < 0) return 0;
    return (i64)f[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve() {
    i64 n = read(), m = read();
    i64 ans = 0;
    int len = 64 - __builtin_clzll(n);
    std::string high = std::bitset<70>(n).to_string();
    high = high.substr(70 - len, len);
    // std::cerr << high << '\n';
    for (int j = 1; j <= m; j++) {
        auto dfs = [&](auto self, int i, int count_num, bool limit_high) -> i64 {
            if (i == len) return count_num == j;
            if (limit_high == false) return C(j - count_num, len - i);

            int hi = limit_high ? high[i] - '0' : 1;
            i64 res = 0;

            for (int k = 0; k <= hi; k++) {
                if (k == 1)
                    res = (res + self(self, i + 1, count_num + 1, limit_high && k == hi) + mod) % mod;
                else
                    res = (res + self(self, i + 1, count_num, limit_high && k == hi) + mod) % mod;
            }
            return res;
        };
        ans = (ans + j * dfs(dfs, 0, 0, true) + mod) % mod;
    }
    std::cout << ans << '\n';
}

signed main() {
    init();
    int T = read();
    while (T--) solve();
}
