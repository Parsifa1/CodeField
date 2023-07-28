#include<bits/stdc++.h>
using namespace std;
int a[114],b[114],n,ans,p,q,k,t;

int bet() {
    k=0;
    q=0;
    p=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]==b[i])
            k++;
    }
    


    if(k==n) {
        cout<<0<<endl;
        return 0;
    }
        
    for(int i=0;i<n;i++) {

        if(b[i]==0)
            p++;
        else if(b[i]==1)
            q++;
        if(a[i]==0)
            p--;
        else if(a[i]==1)
            q--;
    }
    q=abs(q);
    p=abs(p);

    
    if(p<q) {
        q=p;
    }
    if(q+k==n)
        cout<<q<<endl;
    else 
        cout<<q+1<<endl;
    return 0;
    
}


int main() {
    cin>>t;
    for(int j=0;j<t;j++) {
        bet();
    }

}