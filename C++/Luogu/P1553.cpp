#include<bits/stdc++.h>
using namespace std;
string bef, aft, s;
string reverse(string s) {
    string res = "";
    for(int i = s.size() - 1; i >= 0; i--) {
        res += s[i];
    }
    for(int i = 0; i < s.length(); i++) {
        if(res[0] != '0') 
            break;
        else
            res.erase(0, 1);
    }
    return (res != "" ? res : "0");
}

string del(string s) {
    for (int i = s.size() - 1; i >= 0 ; i--) {
        if (s[i] != '0') 
            break;
        else
            s.erase(i, 1);
    }
    return (s != "" ? s : "0");
}
int main() {
    cin >> s;
    if(s.find(".") != string::npos) {
        bef = s.substr(0, s.find("."));
        aft = s.substr(s.find(".") + 1, s.size() - s.find(".") - 1);
        cout << reverse(bef) << "." << del(reverse(aft)) << endl;
        return 0;
    }
    else if(s.find("/") != string::npos) {
        bef = s.substr(0, s.find("/"));
        aft = s.substr(s.find("/") + 1, s.size() - s.find("/") - 1);
        cout << reverse(bef) << "/" << reverse(aft) << endl;
        return 0;
    }
    else if(s.find("%") != string::npos) {
        bef = s.substr(0, s.find("%"));
        cout << reverse(bef) << "%" << endl;
        return 0;
    }
    else {
        cout << reverse(s) << endl;
        return 0;
    }

}