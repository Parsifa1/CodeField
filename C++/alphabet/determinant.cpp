#include <iostream>
using namespace std;
int N;
int main() {
    cout << "请输入行列式的阶数:" << endl;
    cin >> N;
    double a[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> a[i][j];
    for (int k = 0; k < N - 1; k++) {
        for (int i = k + 1; a[k][k] == 0; i++) {
            for (int j = k; j < N; j++)
                a[k][j] += a[i][j];
        }

        for (int i = k; i < N; i++) {
            double x = a[i + 1][k] / a[k][k];
            for (int j = 0; j < N; j++)
                a[i + 1][j] -= x * a[k][j];
        }
    }
    cout << "上三角行列式:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << fixed << a[i][j] << ' ';
        cout << endl;
    }
    double g = a[0][0];
    for (int i = 1; i < N; i++)
        g *= a[i][i];
    cout << "行列式的值为:" << fixed << g;
    return 0;
}
