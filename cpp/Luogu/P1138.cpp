#include <bits/stdc++.h>
using namespace std;
int num[10001];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin>>num[i];
    }
    sort(num+1, num+n+1);
    
        for(int j=1;j<n&&j<k;j++) {
            if(num[j]==num[j+1])
                k++;
        }
    if(k<=n) {
        cout<<num[k];
    }
    else {
        cout<<"NO RESULT";
    }
}