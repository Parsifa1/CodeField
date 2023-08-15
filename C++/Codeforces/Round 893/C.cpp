#include <bits/stdc++.h>
using namespace std;
// #define int long long
map<int, int> mp;
void solve() {
    mp.clear();
    int n; cin >> n;
    vector<int> p;
    for(int i = 1; i <= n; i++) {
        int temp = i;
        if(!mp[i]) {
            while(temp <= n) {
                p.push_back(temp);
                mp[temp]++;
                temp *= 2;
                
            }
        }
    }
    for(auto x : p) cout << x << " ";
    cout << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
}
