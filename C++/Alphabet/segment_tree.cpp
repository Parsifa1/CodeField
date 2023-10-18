#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define ll long long
int a[N], n, m;;

struct node {
    int l, r;
    long long sum, lazy;
} tree[N << 3];

void build (int l, int r, int u) {
    tree[u].r = r, tree[u].l = l;
    if(l == r) {
        tree[u].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, u << 1), build(mid + 1, r, u << 1 | 1);
    tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
}

void spread(int u) {
    if(tree[u].lazy) {
        int lt = u << 1; int rt = u << 1 | 1;
        tree[lt].lazy += tree[u].lazy, tree[rt].lazy += tree[u].lazy;
        tree[lt].sum += tree[u].lazy * (tree[lt].r - tree[lt].l + 1);
        tree[rt].sum += tree[u].lazy * (tree[rt].r - tree[rt].l + 1);
        tree[u].lazy = 0;
    }
}

void update(int L, int R, int u, int add) {
    int l = tree[u].l, r = tree[u].r;
    if(L <=l && r <= R) {
        tree[u].sum += (r - l + 1) * add;
        tree[u].lazy += add;
        return;
    } spread(u);
    int mid = (l + r) >> 1;
    if(L <= mid) update(L, R, u << 1, add);
    if(R > mid) update(L, R, u << 1 | 1, add);
    tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
}
ll query(int L, int R, int u) {
    int l = tree[u].l, r = tree[u].r;
    if(L <= l && r <= R) return tree[u].sum;
    spread(u);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if(L <= mid) ans += query(L, R, u << 1);
    if(R > mid) ans += query(L, R, u << 1 | 1);
    return ans;
}

int main() {
    scanf("%d %d" , &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, n, 1);
    int p, x, y, k;
    for(int i = 1; i <=m; i++) {
        scanf("%d", &p);
        if(p == 1) {
            scanf("%d %d %d", &x, &y, &k);
            update(x, y, 1, k);
        } else {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(x, y, 1));
        }
    }
}
