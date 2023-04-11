#include<bits/stdc++.h>
using namespace std;
int a[3][3] = {{1,2,3},{4,5,6},{7, 8, 9}};
int (*p)[3];
int b[3] = {1,2,3};
int main() {
    p = a;
    cout<<p<<"\n"<<*p<<"\n"<< **p <<endl;
    cout<<sizeof(*p)<<"\n"<<sizeof(**p)<<endl;
    cout<<a<<"\n"<<*a<<"\n"<<**a<<endl;
    cout<<sizeof(a)<<"\n"<<sizeof(*a)<<"\n"<<sizeof(**a)<<endl;
}