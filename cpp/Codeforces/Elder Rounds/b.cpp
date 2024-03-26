#include<bits/stdc++.h>
using namespace std;
int a[114];
bool check(int array[], int n)
{   
    bool flag = 0;

    for(int i = 0; i < n - 1; i++)      
    {         
        if(array[i] == array[i + 1])
            flag = 1;
    }

    return flag;
}

int solve() {
    int s;
    cin>>s;
    for(int i=0;i<s;i++) {
        cin>>a[i];
    }
    sort(a,a+s);
    int mid=check(a,s);
    if(mid==0&&s!=1)
        cout<<"YES"<<endl;
    else if(s==1)
        cout<<"YES"<<endl;
    else if(mid==1&&s!=1)
        cout<<"NO"<<endl;
    return 0;
}

int main() {
    int t;
    cin>>t;
    for(int j=0;j<t;j++) {
    solve();
    }
}