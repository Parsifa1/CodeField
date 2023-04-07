#include <bits/stdc++.h>
using namespace std;
int num, x, y, n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num == 100)
            x++;
        else
            y++;
    }
    if (x!=0&&y!=0) {
        if (2 % (x + 2 * y) == 0 || (x + 2 * y) % 2 == 0)
            cout << "YES";
        else
            cout << "NO";
    }
    else if( x==0&&y!=0&&(y%2==0)) {
        cout << "YES";
    }
    else if(x!=0&&y==0&&x%2==0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}