#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
ll num[N];

int solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    sort(num + 1, num + n + 1);
    ll ans1 = num[1] * num[2];
    ll ans2 = num[n] * num[n - 1];
    if(ans1 > ans2) {
        cout << ans1 << endl;
    } else {
        cout << ans2 << endl;
    }
    return 0;
}



int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}