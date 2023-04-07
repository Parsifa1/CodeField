#include<bits/stdc++.h>
using namespace std;
const int  N = 1e7 + 5;
#define ll long long
ll dp[N],t,m;
ll tim[N],value[N];
int main() {
    cin>> t >> m;
    for(int i = 1;i <= m;i++) {
        cin>> tim[i] >> value[i];
    }
    for(int i = 1; i <= m;i++) {
        for (int j = 0; j <= t; j++) {
            if(j >= tim[i])
                dp[j] = max(dp[j],dp[j - tim[i]] + value[i]);
        }
    }
    cout<< dp[t] << endl;
}
