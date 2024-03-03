#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}


int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<int, int>> s;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        s.push_back(make_pair(a, b));
    }
    
    sort(s.begin(), s.end(), cmp);
    for(int i = 0; i < m; i++) {
        if(n > s[i].second) {
            ans += s[i].first * s[i].second;
            n -= s[i].second;
        } else {
            ans += s[i].first * n;
            break;
        }
    }
    cout << ans << endl;
}