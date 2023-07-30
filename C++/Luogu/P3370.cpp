#include <bits/stdc++.h>
// using namespace std;
// #define int long long
#define ull unsigned long long
const int N = 1e6 + 5;
ull mod = 1 << 30;
int a[10010];
void init() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}

int ans = 0;


ull hash(std::string s) {
    int res = 1;
    for(int i = 0; i < s.length(); i++) {
        res = ((res * 129 + (ull)s[i]) % mod + mod) % mod;
    }
    return res;
}

void solve() {

    int n; std::cin >> n;
    std::vector<std::string> p(n);
    for(int i = 0, res = 0; i < n; i++) std::cin >> p[i];
    // std::cerr << p.size();
    for(int i = 0; i < p.size(); i++) {
        a[i] = hash(p[i]);
        // std::cerr << i << " " << a[i] << std::endl;
    }
    std::sort(a, a + n);
    for(int i = 0; i < p.size(); i++) {
        if(a[i] != a[i + 1]) ans++;
        // std::cerr << a[i] << " " << a[i + 1] << std::endl;
    }
    std::cout << ans << std::endl;


}
signed main() {
    init();
    solve();
}
