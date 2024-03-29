#include <bits/stdc++.h>
using namespace std;

int C(int n) { return (n == 0 ? 0 : n * (n - 1) / 2); }

int solve() {
    int k, n, cnt[3];
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> k;
    for (int i = n; i >= 0; i--) {
        if (C(i) + C(n - i) == k) {
            cnt[1] = i;
            cnt[2] = n - i;
            n = 0;
            k = 0;
            break;
        }
    }

    if (k == 0 && n == 0) {
        cout << "YES\n";
        for (int i = 1; i <= 2; i++) {
            for (int l = 1; l <= cnt[i]; l++) {
                cout << (i == 1 ? 1 : -1) << " ";
            }
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
