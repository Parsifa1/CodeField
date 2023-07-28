#include <bits/stdc++.h>
using namespace std;
int fa[7000], n, m, p;
void init() {
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) fa[i] = i;
}

int find(int x) {
    return fa[x] == x ? x : find(fa[x]);
}

void unite(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    init();
    int x, y , a, b; 
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        unite(x, y);
    }
    for(int i = 1; i <= p; i++) {
        cin >> a >> b;
        if(find(a) == find(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}