#include <bits/stdc++.h>
using namespace std;
int car[101];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> car[i];
    }
    car[0] = -11;
    for (int i = 1; i <= n; i++) {
        // car[i] -= i;
        car[i] -= i;
        if (car[i] <= car[i - 1]) {
            car[i] = car[i - 1] + 1;
        }
        
    }
    for (int i = 1; i <= n; i++) {
        cout << car[i] << endl;
    }
}