## C++读入优化

```c++
// 关闭输入输出缓存，使效率提升
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    // 解除cin和cout的默认绑定，来降低IO的负担使效率提升
```

### 二分

#### 往左找答案

```c++

while (l < r) {
    int mid = (l + r) >> 1;	//(l+r)/2
    if (check(mid))  r = mid;    // check()判断mid是否满足性质,即是否可行
    else l = mid + 1;
}
```

### 往右找答案

```c++
while (l < r) {
    int mid = (l + r + 1) >> 1;	//(l+r+1)/2
    if (check(mid))  l = mid;
    else r = mid - 1;
}
```

### 拓展欧几里得求解线性同余方程组

```c++
namespace EXGCD {
using ll = __int128_t;
ll exgcd(ll a, ll &x, ll b, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll g = exgcd(b, y, a % b, x);
    return y -= a / b * x, g;
}
pair<ll, ll> cal(ll a, ll b, ll c) {
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


```

## KMP ：字符串匹配算法

```c++
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

vector<int> find_occurrences(string text, string pattern) {
  string cur = pattern + '#' + text;
  int sz1 = text.size(), sz2 = pattern.size();
  vector<int> v;
  vector<int> lps = prefix_function(cur);
  for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
    if (lps[i] == sz2)
      v.push_back(i - 2 * sz2);
  }
  return v;
}
```

## 字符串哈希

```c++

ull mod = 1 << 30;
ull hash(std::string s) {
    int res = 1;
    for(int i = 0; i < s.length(); i++) {
        res = ((res * 129 + (ull)s[i]) % mod + mod) % mod;
    }
    return res;
}
```

## 二分图最大匹配 ： 增广路算法

```c++
;#include <assert.h>
#include <vector>

struct augment_path {
    std::vector<std::vector<int> > g;
    std::vector<int> pa;  // 匹配
    std::vector<int> pb;
    std::vector<int> vis;  // 访问
    int n, m;              // 两个点集中的顶点数量
    int dfn;               // 时间戳记
    int res;               // 匹配数

    augment_path(int _n, int _m) : n(_n), m(_m) {
        assert(0 <= n && 0 <= m);
        pa = std::vector<int>(n, -1);
        pb = std::vector<int>(m, -1);
        vis = std::vector<int>(n);
        g.resize(n);
        res = 0;
        dfn = 0;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < m);
        g[from].push_back(to);
    }

    bool dfs(int v) {
        vis[v] = dfn;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pb[u] = v;
                pa[v] = u;
                return true;
            }
        }
        for (int u : g[v]) {
            if (vis[pb[u]] != dfn && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int work() {
        while (true) {
            dfn++;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (pa[i] == -1 && dfs(i)) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                break;
            }
            res += cnt;
        }
        return res;
    }
};

```

## 哈希

```c++
struct Hash {
    vector<ull> has1, has2;
    vector<ull> base1, base2;
    int p1 = 131, p2 = 13331;
    Hash(string s) {
        int n = s.length();
        has1.resize(n + 1, 0);
        has2.resize(n + 1, 0);
        base1.resize(n + 1, 1);
        base2.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            has1[i] = has1[i - 1] * p1 + s[i - 1];
            has2[i] = has2[i - 1] * p2 + s[i - 1];
            base1[i] = base1[i - 1] * p1;
            base2[i] = base2[i - 1] * p2;
        }
    }
    ull calchas1(int l, int r) {
        return has1[r] - base1[r - l + 1] * has1[l - 1];
    }
    ull calchas2(int l, int r) {
        return has2[r] - base2[r - l + 1] * has2[l - 1];
    }
    bool same(int l1, int r1, int l2, int r2) {
        return calchas1(l1, r1) == calchas1(l2, r2) &&
               calchas2(l1, r1) == calchas2(l2, r2);
    }
};

```

### 位运算：

#### 异或；

类似于一种不进位加法，特别是多个数之间异或在一起。如果再次对已经在这个集合中的数异或，那么就相当于把这个数从集合中删除了，如果对没有异或过的数异或，那么就相当于把这个数加入到集合中了。特别的，对于一个数n，n ^ n = 0，n ^ 0 = n。在二进制数位的观点下看，如果几个数的同一个数位上都是1，那么如果有奇数个1，那么这个数位上的结果就是1，如果有偶数个1，那么这个数位上的结果就是0。

#### 或：

首先，我们要把或运算在二进制的视角下看待,两个数之间的或运算，只会越来越大，因为对于每一个数位，如果有一个数位上是1，那么结果就是1，如果两个数位上都是0，那么结果就是0，也就是说，对于a | b，b的每一个数位在或运算之后要不保持不变，要不从0变成1，从而使得结果变大，所以，如果我们要找到一个数，使得a | x最大，那么我们只需要找到一个数x，使得x的每一个数位都是1，那么a | x就是最大的了。

<!-- --2023/9/19 -->

### 随机数生成

```c++
std::mt19937 mt_rand(std::chrono::system_clock::now().time_since_epoch().count()); //随机数生成器

```

### 防止被卡`std::unordered_map`

```c++
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
```

使用`unordered_map<T1, T2, custom_hash> safe_map`来初始化。

### 树状数组

```c++
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};
```

### 快速幂

```cpp
int ksm(int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y & 1) ans = (ll)ans * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ans;
}
```

### 并查集（DSU）

```cpp
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};
```

### 取模类(i64)

```cpp
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<i64 P>
struct MLong {
    i64 x;
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x) : x{norm(x % getMod())} {}

    static i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }
    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr i64 val() const {
        return x;
    }
    explicit constexpr operator i64() const {
        return x;
    }
    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong &operator*=(MLong rhs) & {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator+=(MLong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator-=(MLong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator/=(MLong rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MLong &a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MLong &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

//设置默认模数
template<>
i64 MLong<0LL>::Mod = i64(1E18) + 9;

//逆元
template<int V, int P>
constexpr MLong<P> CInv = MLong<P>(V).inv();

constexpr i64 P = 1000000007;
using Z = MLong<P>;

```

### 取模类(int)

```cpp
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}

    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
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
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
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
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
}

//设置默认模数
template<>
int MInt<0>::Mod = 998244353;

//逆元
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1000000007;
using Z = MInt<P>;

```

### 质数筛筛欧拉函数

```cpp
constexpr int N = 1000000005;
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
```

### 凸包 + 旋转卡壳

```cpp
struct Point {
    i64 x, y;
    Point(i64 x = 0, i64 y = 0) : x(x), y(y) {}
    friend Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
    friend Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
    friend Point operator*(Point A, double p) { return Point(A.x * p, A.y * p); }
    friend Point operator/(Point A, double p) { return Point(A.x / p, A.y / p); }
    friend bool operator<(const Point& a, Point& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
    friend i64 dot(const Point& x) { return x.x * x.x + x.y * x.y; }
    friend double det(Point A, Point B) { return A.x * B.y - B.x * A.y; }
    friend bool operator==(const Point& a, const Point& b) {
        auto dcmp = [](double x) {
            if (fabs(x) < eps)
                return 0;
            else
                return x < 0 ? -1 : 1;
        };
        return !dcmp(a.x - b.x) && !dcmp(a.y - b.y);
    }
};

std::vector<Point> ConvexHull(vector<Point> p) {
    auto n = p.size();
    vector<Point> ch(n + 1);
    sort(p.begin(), p.end());
    int m = 0;
    for (int i = 0; i < n; ++i) {  // 下凸包
        while (m > 1 && det(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; --i) {  // 上凸包
        while (m > k && det(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    return ch;
}
double Rotating_calipers(vector<Point> con) {
    int con_num = con.size() - 1;
    i64 op = 1, ans = 0;
    for (int i = 0; i < con_num; ++i) {
        while (det((con[i] - con[op]), (con[i + 1] - con[i])) <
               det((con[i] - con[op + 1]), (con[i + 1] - con[i])))
            op = (op + 1) % con_num;
        ans = max(ans, max(dot(con[i] - con[op]), dot(con[i + 1] - con[op])));
    }
    return ans;
}
```

### int128重载输出运算符

```cpp
std::ostream& operator<<(std::ostream& out, const __int128 b) {
    std::string s;
    __int128 t = b;
    int sig = 1;
    if (t < 0) sig = -1, t = -t;
    for (; t; t /= 10) s += '0' + t % 10;
    if (sig == -1) s += '-';
    reverse(s.begin(), s.end());
    if (s.length() == 0) s += '0';
    out << s;
    return out;
}

```
