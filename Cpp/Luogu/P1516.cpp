#include <algorithm>
#include <codecvt>
#include <iostream>
#include <numeric>
#include <ostream>

using ll = long long;
namespace EXGCD {
ll exgcd(ll a, ll &x, ll b, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll g = exgcd(b, y, a % b, x);
    return y -= a / b * x, g;
}
std::pair<ll, ll> cal(ll a, ll b, ll c) {
    ll x, y, g = exgcd(a, x, b, y);  // gcd(a, b)
    if (c % g) {
        return {-1, -1};
    }  // ?
    c /= g, x *= c, y *= c;
    ll step = b / g, tx = x % step;
    if (tx <= 0) tx += step;
    ll ty = y - a / g * ((tx - x) / step);
    return {tx, ty};
}  // a * x + b * y = c (x的最小正整数解)
}  // namespace EXGCD
int main() {
    int x, y, m, n, l;
    std::cin >> x >> y >> m >> n >> l;
    if (m > n) {
        std::swap(x, y);
        std::swap(m, n);
    }
    auto [a, b] = EXGCD::cal(n - m, l, x - y);
    if (a == -1) {
        std::cout << "Impossible" << std::endl;
    } else {
        std::cout << a << std::endl;
    }
}
