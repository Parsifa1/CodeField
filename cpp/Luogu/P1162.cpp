#include<bits/stdc++.h>
using namespace std;
int a[31][31],n;

void dfs(int x,int y) {
    if(x<0||y<0||x>n+1||y>n+1||a[x][y]!=0) return;
    a[x][y]=3;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

void init() {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
}

int main() {
    cin>>n;
    init();
    dfs(0,0);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]==0)
                cout<<2<<" ";
            else if(a[i][j]==3)
                cout<<0<<" ";
            else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}