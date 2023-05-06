#include <bits/stdc++.h>
using namespace std;


int solve() {
    int cnt = 0;
    string s;
    cin >> s;
    //codeforces
    if(s[0] != 'c')
        cnt++;
    if(s[1] != 'o')
        cnt++;
    if(s[2] != 'd')
        cnt++;
    if(s[3] != 'e')
        cnt++;
    if(s[4] != 'f')
        cnt++;
    if(s[5] != 'o')
        cnt++;
    if(s[6] != 'r')
        cnt++;
    if(s[7] != 'c') 
        cnt++;
    if(s[8] != 'e')
        cnt++;
    if(s[9] != 's')
        cnt++;
    cout << cnt << endl;
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
