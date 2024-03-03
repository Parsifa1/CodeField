#include<bits/stdc++.h>
using namespace std;
int n,num[10],dtc[10];

void print() {
    for (int i=n;i>0;i--) {
        printf("%5d",num[i]);  
    }
    cout << endl;
}

void dfs(int x) {
    if(x==0) {
        print();
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!dtc[i]) {
            dtc[i]++;
            num[x]=i;
            dfs(x-1);
            dtc[i]--;
        }
    }
}

int main() {
    cin>>n;
    dfs(n);
    return 0;
}   