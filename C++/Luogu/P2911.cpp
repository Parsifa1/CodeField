#include<bits/stdc++.h>
using namespace std;
int s1,s2,s3,ans,maxs,num[1000001],x;

int main() {
    cin>>s1>>s2>>s3;
    for(int i=1;i<=s1;i++) {
        for(int j=1;j<=s2;j++) {
            for(int k=1;k<=s3;k++) {
                num[i+j+k]++;
                maxs=max(maxs,i+j+k);
            }
        }
    }
    for(int i=1;i<=maxs;i++) {
        if(num[i]>ans) {
            ans=num[i];
            x=i;
        }
    }
    cout<<x;
}


//1 2 3 4 5 6 7 8
//0 0 1 3 6 5 3 1