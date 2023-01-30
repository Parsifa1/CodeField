#include <bits/stdc++.h>
using namespace std;
int n;
char a[15][15], b[15][15], c[15][15], d[15][15];

bool dcd() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return 0;
    return 1;
}
bool tr1() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[j][n - i + 1] = a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return 0;
    return 1;
}

bool tr2() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[n - i + 1][n - j + 1] = a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return 0;
    return 1;
}

bool tr3() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[n - j + 1][i] = a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return 0;
    return 1;
}

bool tr4() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[i][n - j + 1] = a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return 0;
    return 1;
}

bool tr5() {
    tr4();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = b[i][j];
    if (tr1())
        return 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[i][j] = a[i][j];
    if (tr2())
        return 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[i][j] = a[i][j];
    if (tr3())
        return 1;
    return 0;

}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    if (tr1()) {
        cout << 1;
        return 0;
    }
    if (tr2()) {
        cout << 2;
        return 0;
    }
    if (tr3()) {
        cout << 3;
        return 0;
    }
    if (tr4()) {
        cout << 4;
        return 0;
    }
    if (tr5()) {
        cout << 5;
        return 0;
    }
    if (dcd()) {
        cout << 6;
        return 0;
    }
    cout << 7;
}
