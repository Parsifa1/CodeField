#include <iostream>
void solve() {
    int n;
    std::cin >> n;
    if (n % 2 != 0) {
        std::cout << "NO" << '\n';;
        return;
    }
    std::cout << "YES" << '\n';
    for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) {
            std::cout << "AA";
        } else {
            std::cout << "BB";
        }
    }
    std::cout << '\n';
}
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
