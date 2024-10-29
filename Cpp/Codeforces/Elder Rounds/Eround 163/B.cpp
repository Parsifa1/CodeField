#include <iostream>
#include <vector>
void solve() {
    int n, flag = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    int pre = 0;

    for (int k : a) {
        int p = k / 10, q = k % 10;
        if (k > 10 && q >= p && p >= pre) {
            pre = q;
        } else {
            if (k >= pre) {
                pre = k;
            } else {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        std::cout << "NO" << '\n';
    else
        std::cout << "YES" << '\n';
}
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
