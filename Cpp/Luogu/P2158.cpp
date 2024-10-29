#include <bits/extc++.h>
using i64 = long long;

template <typename... Args>
void println(std::format_string<Args...> fmt, Args&&... args) {
    std::cout << std::format(fmt, std::forward<Args>(args)...) << '\n';
}
inline i64 read() {
    i64 x = 0, w = 1, ch = std::cin.get();
    for (; (ch >= '0' && ch <= '9') || ch == '-'; ch = std::cin.get())
        ch == '-' ? w = -1 : x = (x * 10 + ch - '0');
    return x * w;
}

constexpr i64 INF = 1e18;
constexpr int N = 40005;

std::vector<int> prime, minp(N), phi(N);

void pre(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) minp[i] = i, phi[i] = i - 1, prime.push_back(i);
        for (auto p : prime) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * phi[p];
        }
    }
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n = read(), ans = 0;
    if (n == 1) {
        println("{}", 0);
        return 0;
    }
    pre(n);
    for (int i = 1; i < n; i++) {
        ans += phi[i];
    }
    println("{}", ans * 2 + 1);
}
