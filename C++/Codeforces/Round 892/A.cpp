#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void solve() {
    int n; cin >> n;
    a.resize(n);
    for(auto &x : a) cin >> x;
    vector<int> b, c;
    sort(a.begin(), a.end());
    // for (auto x : a) cout << x <<" ";
    int maxx = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] >= maxx) {
            maxx = a[i];
            c.push_back(maxx);
        }
        else {
            b.push_back(a[i]);
        }
    }
    if (b.size() == 0) cout << -1 << endl;
    else {
        cout << b.size() <<" " << c.size() << endl;
        for (auto x : b) cout << x <<" ";
        cout << "\n";
        for(auto y : c) cout << y << " ";
        cout << "\n";
    }
}

int main() {
    int T; cin >> T;
    while (T--) solve();
}