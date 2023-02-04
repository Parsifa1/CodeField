#include<bits/stdc++.h>
using namespace std;

int a[114],b[114],i,n;

void cal() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        b[0] = a[0];
        b[i] = a[i] + b[i - 1];
    }
    for (int j = 0; j < n; j++) {
        cout << b[j] << " ";
    }
}
int main() {
    cin>>n;
    cal();
    return 0;
}