#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int id[500005];

int mul(int a, int b, int c, int x) { return a * x * x + b * x + c; }

struct node {
    int a, b, c, x;
} s[500005];

bool operator<(node a, node b) {
    return mul(a.a, a.b, a.c, a.x) > mul(b.a, b.b, b.c, b.x);
}
int main() {
    priority_queue<node> pq;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i].a >> s[i].b >> s[i].c;
    for (int i = 1; i <= m; i++) id[i] = i;
    // for(int i = 1; i <= n; i++) cout << s[i].a << " " << s[i].b << " " << s[i].c;
    for (int i = 1; i <= n; i++) pq.push({s[i].a, s[i].b, s[i].c, id[1]});
    while (!pq.empty()) {
        node z = pq.top();
        ans.push_back(mul(z.a, z.b, z.c, z.x));
        pq.pop();
        pq.push({z.a, z.b, z.c, id[z.x]+1});
        if(ans.size() == m) break;
    }
    for(int i = 0; i < m ; i++) cout << ans[i] << " ";
    cout << endl;
}