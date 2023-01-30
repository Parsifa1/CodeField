#include<bits/stdc++.h>
using namespace std;
int yh[25][25],n;
int main() {
    cin>>n;
    yh[1][1]=1,yh[2][1]=1,yh[2][2]=1;
    int i=1;
    for(int j=1;j<=i;j++) 
        for(i=1;i<=n;i++) {
            yh[i][1]=1;
            yh[i+1][j+1]=yh[i][j]+yh[i][j+1];
        }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) 
            cout<<yh[i][j]<<" ";
        cout<<"\n";
    }
}