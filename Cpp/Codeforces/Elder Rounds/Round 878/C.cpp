#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int a[N], b[N];
 
void solve() {
    int n, k;
    ll ans = 0, q;
    memset(b, 0, sizeof(b));
    scanf("%d %d %lld", &n, &k, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (q >= a[i]) {
            b[i] = 1;
        }
    }
    int count = 0;
    for (int i = 1; i <= n + 1; i++) {
        if(b[i] == 1) {
            count++;
        } else {
            if(count >= k) {
                ans += 1LL * (count - k + 2) * (count - k + 1) / 2;
            }
            count = 0;
        }
        
    }
    printf("%lld\n", ans);
}
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}