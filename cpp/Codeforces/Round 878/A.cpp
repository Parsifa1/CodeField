#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    string s;
    vector<char> v;
    v.clear();
    cin >> s;
    char x = s[0];
    for(int i = 1; i < s.size(); i++) {
        if(x == s[i]) {
            v.push_back(x);
            x = s[i + 1];
            i++;
        }
        else {
            continue;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout<<endl;
}
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}