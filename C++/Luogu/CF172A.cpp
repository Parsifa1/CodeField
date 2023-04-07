#include <bits/stdc++.h>
using namespace std;
string s[30002];
int main() {
    int n, x, j=0;bool flag = true; cin >> n;
    for (int i = 0; i < n; i++) {cin >> s[i];} 
    x = s[0].length();
        for (; j < x && flag; j++) {                   
            for (int i = 0; i < n - 1 && flag; i++) 
                if (s[i][j] != s[i + 1][j]) {flag = false;}           
        } cout << (j ? j - 1 : 0);
}