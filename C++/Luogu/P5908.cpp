#include <bits/stdc++.h>
using namespace std;
// 用vector实现邻接表
vector<int> edge[100005];
// bool vis[100005];

int n, d, ans;
void add(int a, int b) {
    edge[a].push_back(b);
    edge[b].push_back(a);
}
void dfs(int now, int dis, int fa) {
    if (dis >= d) return;
    for (auto i : edge[now]) {
        if (i == fa) continue;
            dfs(i, dis + 1, now);
            ans++;
    }
}

int main() {
    cin >> n >> d;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        add(a, b);
    }
    dfs(1, 0, -1);
    cout << ans << endl;
}