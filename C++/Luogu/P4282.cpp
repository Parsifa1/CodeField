#include <bits/stdc++.h>
using namespace std;
int num[100002], dcd[100002], n, tmp;
char s;
int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &dcd[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }

    cin >> s;

    for (int j = 1; j <= n; j++) {
        cin >> tmp;
        if (s == '+') {
            num[j] += tmp;
        } else if (s == '-') {
            num[j] -= tmp;
        }
    }

    for (int j = n; j > 0; j--) {
        if (num[j] >= dcd[j]) {
            num[j - 1]++;
            num[j] %= dcd[j];
        } else if (num[j] < 0) {
            num[j - 1]--;
            num[j] += dcd[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << num[i] << " ";
    }
    return 0;
}
