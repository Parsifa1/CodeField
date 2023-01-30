#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '{') {
            for (int j = i + 1; j < len; j++) {
                if (s[j] == '}') {
                    s[i] = '(';
                    s[j] = ')';
                    break;
                }
            }
        }
    }
    cout << s;
}
