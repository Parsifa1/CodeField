#include <bits/stdc++.h>
using namespace std;
int b[100001], s, p;
void solve() {
    int n, x, y, m, i = 1;
    cin >> n >> x >> y;
    m = n;
    int ans = n / 2 ? n / 2 : 1;
    int mid = abs(x - y);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= (n+1)/2; i++) {
        if (b[i] == mid) {
            p = 1;
            break;
        } else {
            continue;
        }
    }
    if (p) {
        while (m--) {
            if (b[i] > mid) {
                s++;
            }
            i++;
        }
        if (s >= ans) {
            cout << "El Psy Congroo!" << endl;
        } else {
            cout << "ZERO" << endl;
        }
        p=0;
    } else {
        cout << "ZERO" << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}