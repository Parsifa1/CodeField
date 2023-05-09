#include <bits/stdc++.h>
using namespace std;

bool isPalin(string str) 
{
    string s1(str);
    reverse(s1.begin(), s1.end());
    return str == s1;
}
void solve() {
    string s;
    cin >> s;
    for(auto i = 1; i < s.length(); i++) {
        if(isPalin(s.substr(i,s.length())))
            continue;
        else {
            cout << s.length() - i << endl;
            return;
        }
    } 
    
    cout << -1 << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
        
    }
}
