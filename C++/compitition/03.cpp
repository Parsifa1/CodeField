#include <bits/stdc++.h>
using namespace std;
struct node {
    long long x[4];
    long long y[4];
} a;
int main() {
    cin >> a.x[1] >> a.y[1] >> a.x[2] >> a.y[2] >> a.x[3] >> a.y[3];
    long long t[4];
    t[1] = abs(a.x[1] - a.x[2]) + abs(a.y[1] - a.y[2]);
    t[2] = abs(a.x[1] - a.x[3]) + abs(a.y[1] - a.y[3]);
    t[3] = abs(a.x[2] - a.x[3]) + abs(a.y[2] - a.y[3]);
    
    sort(t + 1, t + 4);
        cout<<t[1]+t[2]<<endl;
    
}
