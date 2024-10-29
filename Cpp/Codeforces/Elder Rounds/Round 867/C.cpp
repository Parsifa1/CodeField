#include<bits/stdc++.h>
using namespace std;
#define ll long long

void work(ll n) {
    int num = 26;
    ll ans = num + (5 + n) * (n - 4) + (n - 4);
    cout << ans << endl;
}
int solve() {
    ll n;
    cin >> n;
    work(n);
    return 0;
}



int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}