#include <bits/stdc++.h>
using namespace std;
string s1, s2;

void solve() {
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 = s1 + s2;
    cout << s1 << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}