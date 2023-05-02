#include <bits/stdc++.h>
using namespace std;

void solve() {
    int ans = 0;
    int n;
    cin >> n;
    if(n % 2 == 0) {
        ans = 2 + ((n - 1) * n) / 2;
    } else {
        ans = 2 + ((n - 2) * (n + 1)) / 2;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}