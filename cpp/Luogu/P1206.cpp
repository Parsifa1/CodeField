#include <bits/stdc++.h>
using namespace std;
int Map1[301];
int Map2[301];
int turn(int n, int num, int x) {
    if (x == 1) {
        int r = 0;
        while (num) {
            Map1[++r] = num % n;
            num /= n;
        }
        Map1[0] = r;
    } else {
        int r = 0;
        while (num) {
            Map2[++r] = num % n;
            num /= n;
        }
        Map2[0] = r;
    }

    return 0;
}

bool judge(void) {
    for (int i = 1; i <= Map2[0]; i++) {
        if (Map2[i] != Map2[Map2[0] - i + 1])
            return false;
    }
    return true;
}

int out(int x) {
    if (x == 1) {
        for (int i = Map1[0]; i >= 1; i--) {
            if (Map1[i] >= 0 && Map1[i] <= 9) {
                cout << Map1[i];
            } else {
                cout << (char)(Map1[i] - 10 + 'A');
            }
        }
    }
    if (x == 2) {
        for (int i = Map2[0]; i >= 1; i--) {
            if (Map2[i] >= 0 && Map2[i] <= 9) {
                cout << Map2[i];
            } else {
                cout << (char)(Map2[i] - 10 + 'A');
            }
        }
    }
    return 0;
}

int main() {
    int b;
    cin >> b;
    for (int j = 1; j <= 300; j++) {
        turn(b, j * j, 2);
        turn(b, j, 1);
        if (judge()) {
            out(1);
            cout << " ";
            out(2);
            cout << endl;
        }
    }
}