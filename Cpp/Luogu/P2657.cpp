#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 INF = 1e18;

inline auto read() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    return [](auto x) { return std::cin >> x, x; }(0ll);
}

void solve() {
    int a = read(), b = read();
    std::string low = std::to_string(a);
    std::string high = std::to_string(b);
    int n = high.size();
    low = std::string(n - low.size(), '0') + low;  // 补前导零，和 high 对齐
    // int diff = n - s.size();
    std::vector<i64> memo(n, -1);

    auto dfs = [&](auto self, int i, bool limit_low, bool limit_high) -> long long {
        if (i == low.size()) return 1;

        if (!limit_low && !limit_high && memo[i] != -1) {
            return memo[i];  // 之前计算过
        }

        int lo = limit_low ? low[i] - '0' : 0;
        int hi = limit_high ? high[i] - '0' : 9;

        i64 res = 0;
        // if (i < diff) {  // 枚举这个数位填什么
        //     for (int d = lo; d <= min(hi, limit); d++) {
        //         res += self(self, i + 1, limit_low && d == lo, limit_high && d == hi);
        //     }
        // } else {  // 这个数位只能填 s[i-diff]
        //     int x = s[i - diff] - '0';
        //     if (lo <= x && x <= min(hi, limit)) {
        //         res = self(self, i + 1, limit_low && x == lo, limit_high && x == hi);
        //     }
        // }

        if (!limit_low && !limit_high) memo[i] = res;

        return res;
    };
}

signed main() {
    int T = read();
    while (T--) solve();
}
