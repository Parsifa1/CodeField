#include <bits/stdc++.h>
using namespace std;
char fie[4][4];
void solve() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> fie[i][j];
        }
    }
    for (int i = 1; i <= 3; i++) {
        if (fie[i][1] == fie[i][2] && fie[i][2] == fie[i][3]) {
            if (fie[i][1] != '.') {
                cout << fie[i][1] << endl;
                return;
            }
        }
        if (fie[1][i] == fie[2][i] && fie[2][i] == fie[3][i]) {
            if (fie[1][i] != '.') {
                cout << fie[1][i] << endl;
                return;
            }
        }
        if ((fie[1][1] == fie[2][2] && fie[2][2] == fie[3][3])) {
            if (fie[1][1] != '.') {
                cout << fie[1][1] << endl;
                return;
            }
        }
        if (fie[1][3] == fie[2][2] && fie[2][2] == fie[3][1]) {
            if (fie[1][3] != '.') {
                cout << fie[1][3] << endl;
                return;
            }
        }
    }
    cout << "DRAW" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}