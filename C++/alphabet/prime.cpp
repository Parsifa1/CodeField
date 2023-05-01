#include <bits/stdc++.h>
using namespace std;

int t, n, prime[100001] = {0};
bool all[100001] = {0};

int main() {
    cin >> n;

    for (int i = 2; i < n; i++) {
        if (all[i] == 0) {
            prime[t++] = i;
        }

        for (int j = 0; j < t && i * prime[j] <= n; j++) {
            all[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0; i < t; i++) {
        cout << prime[i] << " ";
    }
    system("pause");
    return 0;
}
