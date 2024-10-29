// Luogu P1125
#include <bits/stdc++.h>
using namespace std;

int prime[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
               43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int num[27];
int main() {
    string s;
    cin >> s;
    int maxn, minn;
    for (auto i = 0; i < (int)s.length(); i++) {
        num[s[i] - 'a' + 1]++;
    }
    sort(num + 1, num + 27);
    maxn = num[26];
    for(int j = 1; j <= 26; j++) {
        if (num[j] != 0) {
            minn = num[j];
            break;
        }
    }
    for (auto i = 0; i < 25; i++) {
        if (maxn - minn == prime[i]) {
            cout << "Lucky Word" << endl;
            cout << prime[i] << endl;
            return 0;
        }
    }
    cout << "No Answer" << endl;
    cout << 0 << endl;
    return 0;
}