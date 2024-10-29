#include <bits/extc++.h>
using i64 = long long;
constexpr i64 INF = 1e18;

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

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int x = read(), y = read();
    if (x == y) {
        println("{}", 1);
        return 0;
    }
    int res = x * y, ans = 0;
    for (int i = 1; i <= sqrt(res); i++) {
        if (res % i == 0) {
            if (std::gcd(i, res / i) == x && std::lcm(i, res / i) == y) ans++;
        }
    }
    println("{}", ans * 2);
}
