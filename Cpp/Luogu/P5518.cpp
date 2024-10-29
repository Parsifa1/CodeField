#include <bits/extc++.h>
using i64 = long long;
constexpr int N = 1e5 + 45;

template <class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template <int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}

    constexpr i64 mul(i64 a, i64 b, i64 p) {
        i64 res = a * b - i64(1.L * a * b / p) * p;
        res %= p;
        if (res < 0) {
            res += p;
        }
        return res;
    }
    static inline int Mod;
    constexpr static int getMod() {
        if (P > 0)
            return P;
        else
            return Mod;
    }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }
    constexpr int norm(int x) const {
        if (x < 0) x += getMod();
        if (x >= getMod()) x -= getMod();
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        i64 v = a.val();
        return os << v;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
};

using Z = MInt<0>;

constexpr auto sieve() {
    std::vector<int> minp(N + 5, 0), primes;
    std::vector<int> mu(N + 5);

    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (minp[i] == 0) {
            mu[i] = -1;
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
            mu[i * p] = -mu[i];
        }
    }
    return mu;
}

constexpr auto cal_inv() {
    std::vector<Z> inv(N + 5);
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = Z(i).inv();
    }
    return inv;
}

auto cal_Finv(std::vector<Z> &F) {
    std::vector<Z> Finv(N + 5);
    for (int i = 1; i <= N; i++) {
        Finv[i] = F[i].inv();
    }
    Finv[0] = Z(1);
    return Finv;
}

auto cal_F(std::vector<Z> inv, std::vector<int> mu) {
    std::vector<Z> F(N + 5, Z(1));
    for (int i = 1; i <= N; i++) {         // 枚举d
        for (int j = i; j <= N; j += i) {  // 枚举d的倍数
            if (mu[j / i] == 1) F[j] = F[j] * Z(i);
            if (mu[j / i] == -1) F[j] = F[j] * inv[i];
        }
    }
    for (int i = 2; i <= N; i++) F[i] = F[i] * F[i - 1];
    return F;
}

auto calc1(std::vector<Z> F, std::vector<Z> Finv, int A, int B, int C) {
    auto cal_gcd = [&F, &Finv](int A, int B, int C) {
        Z ans = 1;
        for (int l = 1; l <= std::min(A, B); l++) {
            int r = std::min(A / (A / l), B / (B / l));
            ans *= power(F[r] * Finv[l - 1], 1LL * (A / l) * (B / l));
            l = r;
        }
        ans = power(ans, C);
        return ans.inv();
    };
    auto cal_i = [](int A, int B, int C) {
        Z ansi = 1;
        for (int i = 1; i <= A; i++) ansi *= Z(i);
        ansi = power(ansi, 1LL * B * C);
        return ansi;
    };
    auto ans = cal_gcd(A, B, C) * cal_i(A, B, C);
    ans *= cal_gcd(A, C, B) * cal_i(B, A, C);
    return ans;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int T, P;
    std::cin >> T >> P;
    Z::setMod(P);
    auto F = cal_F(cal_inv(), sieve());
    auto Finv = cal_Finv(F);
    while (T--) {
        int A, B, C;
        std::cin >> A >> B >> C;
        std::cout << calc1(F, Finv, A, B, C) << " 0 0\n";
    }
    return 0;
}
