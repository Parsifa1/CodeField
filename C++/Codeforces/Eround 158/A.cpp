#include <algorithm>
#include <iostream>
#include <vector>
void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for(auto &x : a) std::cin >> x;
    int res = std::max(a[0], 2 * (x - a[n - 1]));
    for(int i = 1; i < n; i++) 
        res = std::max(res, a[i] - a[i - 1]);
    std::cout << res << "\n";
}

int main() {
    int t; std::cin >> t;
    while(t--) solve();
}
