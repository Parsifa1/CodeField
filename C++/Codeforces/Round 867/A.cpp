#include<bits/stdc++.h>
using namespace std;

struct node {
    int a, b;
}num[101];

int solve() {
    int n, t = 0, ans = -1, temp = 0;
    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> num[i].a;
    }
    for(int i = 1; i <= n; i++) {
        cin >> num[i].b;
    }
    for(int i = 1; i <= n; i++) {
        int mid = t - i + 1;
        if(mid >= num[i].a) {
            if(temp < num[i].b) {
                temp = num[i].b;
                ans = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}



int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}