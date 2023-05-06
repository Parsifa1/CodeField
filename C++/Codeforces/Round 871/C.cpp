#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
    int t;
    string s;
    int id;
    // id:1,2,3,4;
} num[N];
void solve() {
    int n, ans1 = 200001, ans2 = 200001, ans3 = 200001;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> num[i].t;
        cin >> num[i].s;
        if (num[i].s == "10")
            num[i].id = 1;
        else if (num[i].s == "01")
            num[i].id = 2;
        else if (num[i].s == "11")
            num[i].id = 3;
        else
            num[i].id = 4;
    }
    for (int i = 1; i <= n; i++) {
        if (num[i].id == 1) {
            ans1 = min(ans1, num[i].t);
        } else if (num[i].id == 2) {
            ans2 = min(ans2, num[i].t);
        } else if (num[i].id == 3) {
            ans3 = min(ans3, num[i].t);
        }
    }
    if ((ans1 == 200001 || ans2 == 200001) && ans3 == 200001) {
        cout << -1 << endl;
        return;
    } else if (ans1 + ans2 < ans3) {
        cout << ans1 + ans2 << endl;
        return;
    } else {
        cout << ans3 << endl;
        return;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
