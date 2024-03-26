#include<bits/stdc++.h>
using namespace std;
string a,b;

int solve() {
    cin>>a>>b;
    char s='S';
    char l='L';
    char m='M';
    char x='X';
    char mid1,mid2;
    int numx1=0,numx2=0;
    for(int i=0;;i++) {
        if(a[i]==x) {
            numx1++;
            //cout<<numx1<<" "<<numx2;
        }
        if(a[i]==s||a[i]==l||a[i]==m) {
            mid1=a[i];
            break;
        }
        
    }
    for(int i=0;;i++) {
        if(b[i]==x)
            numx2++;
        if(b[i]==s||b[i]==l||b[i]==m) {
            mid2=b[i];
            break;
        }
        
    }
    //cout<<numx1<<" "<<numx2;
    if(mid1==mid2) {
        if((numx1<numx2&&mid1==l)||(numx1>numx2&&mid1==s))
            cout<<"<"<<endl;
        else if((numx1>numx2&&mid1==l)||(numx1<numx2&&mid1==s))
            cout<<">"<<endl;
        else
            cout<<"="<<endl;
    }
    else {
        if((mid1==s&&mid2==l)||(mid1==s&&mid2==m)||(mid1==m&&mid2==l))
            cout<<"<"<<endl;
        if((mid2==s&&mid1==l)||(mid2==s&&mid1==m)||(mid2==m&&mid1==l))
            cout<<">"<<endl;
    }
    return 0;
}      

int main() {
    int t=0;
    cin>>t;
    for(int j=0;j<t;j++) {
        solve();
    }
}
