#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int vis[3][N][N], sqr[N][N], ans[N][N];  // 0为行，1为列，2为九宫格
int num[82], flag, maxx;                 // 对应每个格子的数字
struct node {
    int line, zero;
} row[N];

bool cmp(node a, node b) {
    return a.zero < b.zero;
}

int WhichBox(int i, int j) {
    if (i <= 3) {
        if (j <= 3)
            return 1;
        else if (j <= 6)
            return 2;
        else
            return 3;
    } else if (i <= 6) {
        if (j <= 3)
            return 4;
        else if (j <= 6)
            return 5;
        else
            return 6;
    } else {
        if (j <= 3)
            return 7;
        else if (j <= 6)
            return 8;
        else
            return 9;
    }
}

int HowMuch(int x, int y) {
    if (x == 1 || y == 1 || x == 9 || y == 9)
        return 6;
    else if (x == 2 || y == 2 || x == 8 || y == 8)
        return 7;
    else if (x == 3 || y == 3 || x == 7 || y == 7)
        return 8;
    else if (x == 4 || y == 4 || x == 6 || y == 6)
        return 9;
    else
        return 10;
}

int fee() {
    int sum = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            sum += ans[i][j] * HowMuch(i, j);
        }
    }
    return sum;
}

void input() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> sqr[i][j];
            if (sqr[i][j] == 0) {
                row[i].line = i;
                row[i].zero++;
            } else {
                vis[0][i][sqr[i][j]] = 1;
                vis[1][j][sqr[i][j]] = 1;
                ans[i][j] = sqr[i][j];
                vis[2][WhichBox(i, j)][sqr[i][j]] = 1;
            }
        }
    }
    sort(row + 1, row + 10, cmp);
    int cnt = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++) {
            cnt++;
            num[cnt] = 9 * (row[i].line - 1) + j;
        }
}

void dfs(int wh) {
    if (wh == 82) {
        flag = 1;
        maxx = max(maxx, fee());
        return;
    }
    int x = num[wh] / 9 + 1;  // 现在这个序号对应的是第x行，第y列
    int y = num[wh] % 9;
    if (y == 0)
        x = num[wh] / 9, y = 9;
    if (!sqr[x][y]) {
        for (int k = 1; k <= 9; k++) {
            if (!vis[0][x][k] && !vis[1][y][k] && !vis[2][WhichBox(x, y)][k]) {
                ans[x][y] = k;
                vis[0][x][k] = 1, vis[1][y][k] = 1,
                vis[2][WhichBox(x, y)][k] = 1;
                dfs(wh + 1);
                vis[0][x][k] = 0, vis[1][y][k] = 0,
                vis[2][WhichBox(x, y)][k] = 0;
            }
        }
    } else {
        dfs(wh + 1);
    }
}

int main() {
    input();
    dfs(1);

    if (flag)
        cout << maxx;
    else
        cout << -1;
}