#include <bits/stdc++.h>
using namespace std;

int num[10005];
void solve() {
    int m, n;
    cin >> m >> n;
    int sum = m * n;
    for (auto i = 0; i < sum; i++) {
        cin >> num[i];
    }
    sort(num, num + sum);
    int max = num[sum - 1];
    int submax = num[sum - 2];
    int min = num[0];
    int submin = num[1];
    if (n > m) {
        int s1 = (max - submin) >= (submax - min)
                ? (n - 1) * m * (max - min) + (m - 1) * (max - submin)
                : (n - 1) * m * (max - min) + (m - 1) * (submax - min);
        cout << s1 << endl;

    } else {
        int s2 = (max - submin) >= (submax - min)
                ? n * (m - 1) * (max - min) + (n - 1) * (max - submin) 
                : n * (m - 1) * (max - min) + (n - 1) * (submax - min);
        cout << s2 << endl;
    }
    
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
