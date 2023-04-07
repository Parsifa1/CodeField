// Luogu P1914
#include <bits/stdc++.h>
using namespace std;

//ascii中， a-z 97-122, A-Z 65-90
int main() {
    int n;
    string exist_s, after_s;
    cin >> n >> exist_s;
    int flag = (int)exist_s[0] + n;
    for (auto i = 0; i < (int)exist_s.length(); i++) {
        int flag = (int)exist_s[i] + n;
        if(flag<=122)
            after_s += (char)flag;
        else
            after_s += (char)(flag-26);
    }
    cout << after_s << endl;
}