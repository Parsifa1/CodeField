#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, k, c;
ll ans;

vector<int> edges[N];
int dfs(int u, int fa, int dep) {
    int mxd1 = 0, mxd2 = 0;
    for (int v : edges[u]) {
        if (v == fa) continue;
        int d = dfs(v, u, dep + 1) + 1;
        if (d > mxd1)
            mxd2 = mxd1, mxd1 = d;
        else
            mxd2 = max(mxd2, d);
    }
    ans = max(ans,1LL * mxd1 * k + max(0LL, 1LL * mxd2 * (k - c) - 1LL * dep * c));
    return mxd1;
}
void solve() {
    scanf("%d%d%d", &n, &k, &c);
    ans = 0;
    for (int i = 1; i <= n; i++) edges[i].clear();
    for (int i = 0, u, v; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, -1, 0);
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
}
