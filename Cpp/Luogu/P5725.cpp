#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n*n;i+=n) {
        for(int j=i;j<=i+n-1;j++)
            printf("%02d",j);
        cout<<endl;
    }
    cout<<"\0"<<endl;;
    int flag=0;
    for(int i=1;i<=n*(n+1)/2;i+=flag) {
        flag++;
        for(int k=0;k<n-flag;k++)
                cout<<"  ";
        for(int j=i;j<=flag*(flag+1)/2;j++) {  
            cout<<setfill('0')<<setw(2)<<j;
        }
        cout<<endl;
    
    }

}