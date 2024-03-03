#include <bits/stdc++.h>
using namespace std;
const int N = 10000002;
int a[N], b[N];
long long ans;


void merge_sort(int l, int r) {
    if (l == r) return;
    int i = l, mid = (l + r) / 2, j = mid + 1, k = l;
    merge_sort(l, mid), merge_sort(mid + 1, r);
     while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            ans += mid - i + 1;
            b[k++] = a[j++];
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = b[i];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n - 1);
    cout << ans << endl;
}