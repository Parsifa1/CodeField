#include <bits/stdc++.h>
using namespace std;
#define ll long long
// const int N = 1e5 + 5;
 
void solve() {
    int n, k;
    // ll ans;
    scanf("%d%d", &n, &k);
    if(k >= 31) cout << n + 1 << endl;
    else {
        
        cout << min((n + 1), (1 << k))<< endl;
    }
}
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}