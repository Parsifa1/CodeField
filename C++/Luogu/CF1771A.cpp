#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 1e5 + 5;
ll num[N];



void solve() {
    int n;
    cin >> n;
    ll maxn = 0;
    ll minn = 0;
    for (int i = 0; i < n; i++) cin >> num[i];

    sort(num, num + n);
    if (num[0] == num[n - 1]) {
        cout << (ll)n * (n - 1) << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (num[i] == num[0]) {
            minn++;
        } else {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (num[i] == num[n - 1]) {
            maxn++;
        } else {
            break;
        }
    }
    ll ans = 2 * (maxn * minn);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}