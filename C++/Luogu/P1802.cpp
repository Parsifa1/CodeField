#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 10;
ll dp[N][N], x, n, ans;
ll win[N], lose[N], p[N], delta[N];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> lose[i] >> win[i] >> p[i];
        ans += lose[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = max(dp[i - 1][j], (j < p[i]) ? dp[i - 1][j] : dp[i - 1][j - p[i]] + win[i] - lose[i]);
        }
    }
    cout <<  ( dp[n][x]);
}
