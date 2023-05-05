#include <bits/stdc++.h>
using namespace std;
int match[100005];

int n;
string s;
vector<int> ans;
void dfs(int l, int r) {
    if(l > r) return;
    if(l == r) {
        cout << l + 1 << " ";
        return;
    }
    for(auto i = l; i <= r; ++i) {
        if(s[i] == '(') {
            dfs(i + 1, match[i] - 1);
            cout << match[i] + 1 << " ";
            cout << i + 1 << " ";
            i = match[i];
        } else {
            cout << i + 1 << " ";
        }
    }
    
}

int main() {
    cin >> n  >> s;
    // s += " ";
    vector<int>stack;
    for(auto i = 0; i < s.size(); ++i) {
        if(s[i] == '(') {
            stack.push_back(i);
        } else if (s[i] == ')') {
            match[i] = stack.back();
            match[stack.back()] = i;
            stack.pop_back();
        }
    }
    dfs(0, n - 1);
  }