#include <iostream>
#include <vector>
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x = s[i];
        if (x == '1') res++;
    }
    if (res == 2) {
        std::vector<int> t;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') t.push_back(i);
        }
        if (t[1] - t[0] == 1) {
            std::cout << "NO" << '\n';
            return;
        }
    }
    if (res % 2 != 0) {
        std::cout << "NO" << '\n';
        return;
    }
    std::cout << "YES" << '\n';
}
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
