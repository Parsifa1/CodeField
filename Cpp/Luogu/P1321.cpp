#include <bits/stdc++.h>
using namespace std;

int boy, girl;
int main() {
    string s; cin >> s;
    for (int i = 0; i < s.length() - 2; i++) {
        if (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y')
            boy++;
    }
    for(int i = 0; i < s.length() - 3; i++) {
        if (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' ||
            s[i + 3] == 'l')
            girl++;
    }
    cout << boy << '\n' << girl << '\n';
}