#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> p;
void bfs(ll u) {
    priority_queue<ll,vector<ll>,greater<ll>> q;
    while (!q.empty()) q.pop();
    q.push(u);
    
    while (!q.empty()) {
        if(p.size() == n) break;
        ll x = q.top();
        int cnt = 0;
        for(auto i : p) if(i == x) cnt = 1;
        if(cnt ==0) p.push_back(x);
        q.pop();
        ll y = 2 * x + 1, z = 3 * x + 1;
        q.push(y);
        q.push(z);
    }
}

int main() {
    cin >> n; 
    p.clear();
    bfs(1);
    for(int i = 0; i < n; i++) cout << p[i] << " ";
    
}