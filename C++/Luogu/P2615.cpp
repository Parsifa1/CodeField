#include <bits/stdc++.h>
using namespace std;
int main() {
    string b, d;
    getline(cin, b);
    getline(cin, d);
    for (size_t i = 0; i < b.length(); ++i) {
        b[i] = tolower(b[i]);
    }
    for (size_t i = 0; i < d.length(); ++i) {
        d[i] = tolower(d[i]);
    }
    
    b=' '+b+' ';
    d=' '+d+' ';
    
    if (d.find(b)==string::npos){
        cout<<-1<<endl;
    }

    else {
        int _a=d.find(b);
        size_t _b=d.find(b),s=0;
        while (_b!=string::npos){
            ++s;
            _b=d.find(b,_b+1);
        }
        cout<<s<<" "<<_a<<endl;
    return 0;
    }
}