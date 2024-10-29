#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[10001],b[10001],g[10001],k[10001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int rg, rk;
        cin>>a[i]>>b[i]>>rg>>rk;
        g[i] = a[i]+rg;
        k[i] = b[i]+rk;
        }
    int x, y;
    cin >> x >> y;
    int im = -1;
    for (int i = 1; i <= n; i++) {
        if (x >= a[i] && x <= g[i] && y >= b[i] && y <= k[i]) {
            im = i;
        }
    }
    cout << im;
}