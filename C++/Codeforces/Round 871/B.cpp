#include <bits/stdc++.h>
using namespace std;

int num[104],ans;
int solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    ans = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        if(num[i] == 0) {
            while(num[i++] == 0 && i < n) {
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
