#include<bits/stdc++.h>
using namespace std;
int n, num[101],dcd[101],u;
int main() {
    cin >> n;
    u = n;
    for (int i = 1; i <= n;i++) {
        cin >> num[i];
    }
    sort(num + 1, num + n + 1);
    for (int i = 1; i < n;i++) {
        if(num[i]==num[i+1]) {
            dcd[i + 1] = 1;
            u--;
        }
    }
    cout << u << endl;
    for (int i = 1; i <= n;i++) {
        if(!dcd[i]) {
            cout << num[i]<<" ";
        }
    }
}
