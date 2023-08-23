#include <bits/stdc++.h>
using namespace std;

vector<int> p, v, ans, vis;
string a, b, c; 
int n; 

bool ok() {
    for(int i = n - 1; i >= 0; i--) {
        if(ans[a[i]] == -1 || ans[b[i]] == -1 || ans[c[i]] == -1) continue;
        if((ans[a[i]] + ans[b[i]]) % n != ans[c[i]]) {
            if((ans[a[i]] + ans[b[i]] + 1) % n != ans[c[i]]) return 0; 
        }
    }
    return 1;
}

void work() {
    int res = 0;
    for(int i = n - 1; i >= 0; i--) {
        int sum = ans[a[i]] + ans[b[i]] + res;
        if(sum % n != ans[c[i]]) return;
        res = sum / n;
    }
    for(int i = 'A'; i <= 'A' + n - 1; i++) cout << ans[i] << ' ';
    exit(0);
}

void dfs(int now) {
    if (now > n) {
        work();
        return;
    }
    for(int i = n - 1; i >= 0; i--) {
        if(vis[i]) continue;
        ans[p[now] + 'A'] = i;
        if(ok()) {
            vis[i] = 1;
            dfs(now + 1);
            vis[i] = 0;
        }
        ans[p[now] + 'A'] = -1;
    
    }
}

signed main() {
    cin >> n;
    p.clear(), v.clear(), ans.clear(), vis.clear();
    v.resize(n), ans.resize('Z', -1), vis.resize(n);
    
    cin >> a >> b >> c;
    for(int i = a.length() - 1; i >= 0; i--) {
        if(!v[a[i] - 'A']) p.push_back(a[i] - 'A'), v[a[i] - 'A']++;
        if(!v[b[i] - 'A']) p.push_back(b[i] - 'A'), v[b[i] - 'A']++;
        if(!v[c[i] - 'A']) p.push_back(c[i] - 'A'), v[c[i] - 'A']++;
    }
    dfs(0);
    return 0;
}