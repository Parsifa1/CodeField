#include <bits/stdc++.h>
using namespace std;
using lll = __int128_t;
using ll = long long;
vector<int> ans;

void solve() {
    int n; cin >> n;
    int m = (n * (n - 1)) / 2;
    int b[m];
    for(int i = 0; i < n; i++) b[i] = 0;
    ans.clear();
    
    // cout << m << endl;;
    for (int i = 1; i <= m; i++) cin >> b[i];

    sort(b + 1, b + m + 1);
    for(int i = 1, j = 1; i <= n; i++) {
        // cout << m << endl;
        ans.push_back(b[j]);
        // cout << j << " " << b[j] << endl;
        j += n - i;  
        if(j > m) break;
    }
    while(ans.size() < n) ans.push_back(1e9);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    } 
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
