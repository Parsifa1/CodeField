#include <bits/stdc++.h>
using namespace std;
int ts1 = 1;
int taozi(int ts) {
    if (ts == 1) {
        return ts1;
    } else {
        ts1 = (ts1 + 1) * 2;
        return taozi(--ts);
    }
}
int main() {
    int ts2;
    cin >> ts2;
    cout << taozi(ts2);
    return 0;
}