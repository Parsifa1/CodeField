#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int dp[N][N];
int val[31];
int main() {
    int V, n;
    cin >> V;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> val[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= V; j ++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= val[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - val[i]] + val[i]);
            }
        }
    }
    cout << V - dp[n][V];
}