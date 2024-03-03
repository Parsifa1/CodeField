#include <bits/stdc++.h>
using namespace std;

inline auto read() { 
    long long f = 1, x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar();}
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    return x * f;
}

int V[61][3], P[61][3];

int main() {
    int n = read(), m = read();
    int k = 0;
    for(int i = 0; i < m; i++) {
        int v = read(), p = read(), q = read();
        if(q == 0) V[i][0] = v, P[i][0] = p, k++;
        else if(!V[q - 1][1]) V[q - 1][1] = v, P[q - 1][1] = p;
        else if(!V[q - 1][2]) V[q - 1][2] = v, P[q - 1][2] = p;
    }
    // int ans = 0;
    vector<int> dp(n + 1);
    for(int i = 0; i < m; i++) {
        for(int j = n; j >= 1; j--) {
            if(j >= V[i][0] + V[i][1] + V[i][2])
                dp[j] = max(dp[j], dp[j - V[i][1] - V[i][2] - V[i][0]] + V[i][1] * P[i][1] + V[i][2] * P[i][2] + V[i][0] * P[i][0]);
            if(j >= V[i][0] + V[i][1])
                dp[j] = max(dp[j], dp[j - V[i][1] - V[i][0]] + V[i][1] * P[i][1] + V[i][0] * P[i][0]);
            if(j >= V[i][0] + V[i][2])
                dp[j] = max(dp[j], dp[j - V[i][2] - V[i][0]] + V[i][2] * P[i][2] + V[i][0] * P[i][0]);
            if(j >= V[i][0])
                dp[j] = max(dp[j], dp[j - V[i][0]] + V[i][0] * P[i][0]);
        }
    }
    cout << dp[n] << "\n";

} 