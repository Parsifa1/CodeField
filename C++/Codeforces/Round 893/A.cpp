#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6 + 5;

vector<int> arr;
void solve() {
    int a, b, c; cin >> a >> b >> c;
    if(a > b) {
        cout << "First" << endl;
        return;
    }
    if(a < b) {
        cout << "Second" << endl;
        return;
    }
    if(a == b) {
        if(c % 2 == 0) cout << "Second" << endl; 
        else {
            cout << "First" << endl;
        }
        return;
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
}
