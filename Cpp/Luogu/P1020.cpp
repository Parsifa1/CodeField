#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 INF = 1e18;

inline bool chmax(auto &a, auto b) { return (a < b) ? a = b, true : false; }

inline bool chmin(auto &a, auto b) { return (a > b) ? a = b, true : false; }

inline auto read() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    return [](i64 x) { return std::cin >> x, x; }(0);
}

signed main() {
    std::vector<int> a(1e5 + 4);
    int n = -1;
    while ((a[++n] = read()));
    std::vector<int> ans, res;
    ans.push_back(a[0]);
    res.push_back(a[0]);
    int j = 0, k = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] <= ans[j])
            ans.push_back(a[i]), j++;
        else
            *std::upper_bound(ans.begin(), ans.end(), a[i], [](int x, int y) { return x > y; }) = a[i];

        if (a[i] > res[k])
            res.push_back(a[i]), k++;
        else
            *std::lower_bound(res.begin(), res.end(), a[i]) = a[i];
    }
    std::cout << j + 1 << '\n' << k + 1 << '\n';
}
