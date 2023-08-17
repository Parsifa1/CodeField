#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 5;

struct node {
    int first, second;
} a[N];

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool cmp(node a, node b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void solve() {
    // priority_queue<node> pq;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first, a[i].second = i;
        // pq.push(a[i]);
    }
    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        if (a[i].first > k) a[i].first = (a[i].first - 1) % k + 1;
    }
    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        cout << a[i].second << " ";
    }
    cout << endl;
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T--) solve();
}
