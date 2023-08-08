#include<bits/stdc++.h>
using namespace std;
vector<int> a;
void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<int> a(s.length() + 10);
    for(int i = 0; i < s.length(); i++) {
        a[s.length() - i - 1] = s[i] - '0';
    }
    for(int i = 0, pos = 0; i < s.length(); i++) {
        if(a[i] >= 5) {
            for(int j = pos; j <= i; j++) a[j] = 0;
            a[i + 1] ++;
            if(i + 1 > n - 1) n++;
            pos = i + 1;
        }
    }
    
    int flag = 0;
    for(int i = n - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) solve();
}