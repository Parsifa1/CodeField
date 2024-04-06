#include<bits/stdc++.h>
using namespace std;

int num[3];

int solve() {
    for(int j=0;j<3;j++) {
        cin>>num[j];
    }
    sort(num,num+3);
    //cout<<num[0]<<num[1]<<num[2]<<endl;
    if(num[0]+num[1]==num[2])
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
        
    return 0;
}



int main() {
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++) {
        solve();
    }

}
