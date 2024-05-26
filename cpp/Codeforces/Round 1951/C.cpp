#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#define int long long
void solve() {
    int n, m, k, ans = 0;
    std::cin >> n >> m >> k;
    std::vector<std::pair<int, int>> a(n), clone(n);
    std::unordered_map<int, int> map;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i].second;
        a[i].first = i;
        clone[i] = a[i];
    }

    std::sort(a.begin(), a.end(), [](auto p, auto q) {
        if (p.second == q.second) return p.first < q.first;
        return p.second < q.second;
    });

    int num = k / m, temp = (k == 0) ? 0 : 1;
    k %= m;
    for (int i = 0; i < num + temp; i++) {
        if (i != num) {
            ans += m * a[i].second;
            map[a[i].first] += m;
        } else {
            ans += k * a[i].second;
            map[a[i].first] += k;
        }
    }

    int buy = 0;
    for (int i = 0; i < n; i++) {
        ans += map[clone[i].first] * buy;
        buy += map[clone[i].first];
    }
    std::cout << ans << '\n';
}
signed main() {
    int T;
    std::cin >> T;
    while (T--) solve();
}
