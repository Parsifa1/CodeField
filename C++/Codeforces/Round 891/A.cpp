#include <bits/stdc++.h>
using namespace std;
using lll = __int128_t;
using ll = long long;
int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if(n == 2 && (a[1] & 1) == 1 && (a[2] & 1) == 0) {
        cout << "NO" << endl;
        return;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if((a[i] & 1)== 1) ans++;
    }
    if((ans & 1) == 1) {
        cout << "NO" << endl;
        return;
    }
    else {
        cout << "YES" << endl;
        return;
    }
}

int main() {
    int T; cin >> T;
    while(T--) cin >> T;
}
