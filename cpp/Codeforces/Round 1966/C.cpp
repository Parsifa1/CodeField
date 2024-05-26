#include <iostream>
#include <set>
#include <vector>
void solve() {
    int n = 0, res = 0;
    std::cin >> n;
    std::vector<int> a(n), p;
    std::set<int> st;
    for (int &x : a) std::cin >> x, st.insert(x);
    for (int x : st) p.push_back(x);
    for (int i = 0; i < p.size() - 1; i++) {
        if (p[i] + 1 != p[i + 1]) {
            res++;
            break;
        }
        res++;
    }
    if (p[0] != 1) {
        std::cout << "Alice\n";
        return;
    }
    if (res % 2 == 0)
        std::cout << "Alice\n";
    else
        std::cout << "Bob\n";
}
signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) solve();
}
