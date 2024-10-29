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
    ll a, b;
    std::cin >> a >> b;
    auto [x, y] = EXGCD::cal(a, b, 1);
        std::cout << x << std::endl;
}
