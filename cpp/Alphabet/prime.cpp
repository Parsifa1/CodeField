#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1000005;
vector<int> prime, minp(N, 0), phi(N, 0);

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) minp[i] = i, phi[i] = i - 1, prime.push_back(i);
        for (auto p : prime) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            } else {
                phi[i * p] = phi[i] * phi[p];
            }
        }
    }
    for (auto x : prime) std::cout << x << " ";
    std::cout << '\n';
    return 0;
}
