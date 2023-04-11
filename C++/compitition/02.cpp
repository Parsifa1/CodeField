#include<bits/stdc++.h>
using namespace std;
string s;
int len=0,t;
int main() {
    cin>>len;
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++) {
        if(s[i]=='a') {
            t++;
        }
    }
    if(t==1) {
        cout<<1<<endl;
    } else {
        cout<<2*t-1<<endl;
    }
}