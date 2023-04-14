#include <iostream>
using namespace std;
// 测试
int main() {
    int t;
    cin >> t;
    int a, b, c, d, e, f;
    while (t--) {
        getchar();
        cin >> a >> b >> c >> d >> e >> f;
        if (((a != c) && (a != e) && (c != e)) ||
            ((b != d) && (b != f) && (d != f)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}