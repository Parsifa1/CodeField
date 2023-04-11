// 提供一个数列a，每次可以任意选择一个a[i],把它变为a[i]/2,问最少需要多少次操作，使得a[i-1]<a[i]<a[i+1](严格单调)。
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = n; i > 1; i--) {
        while (a[i - 1] >= a[i]) {
            if (!a[i - 1]) {
                if (!a[i - 1]) cout << -1 << endl;
                return 0;
            }
            a[i - 1] /= 2;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}