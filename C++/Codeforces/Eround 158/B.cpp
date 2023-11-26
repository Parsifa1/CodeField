#include <iostream>
#include <vector>
void solve() {
    int n; std::cin >> n;
    std::vector<int> c(n);
    for(auto &x : c) std::cin >> x;
    for(int i = 0; i < n; i++) {
        int res = 0;
        while(c[i] != 0) {
            // res += abs();
        }
    }
}
// 1 2 3 12 9 3 2
int main() {
    int T;
    std::cin >> T;
    while (T--) solve();
}
