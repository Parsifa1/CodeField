#include<bits/stdc++.h>
using namespace std;
string s, t;
int nums = 1, numt = 1;

int main() {
    cin>>s>>t;
    for(auto i : s) {
        nums *= (i - 64);
    }
    for(auto i : t) {
        numt *= (i - 64);
    }
    if(nums % 47 == numt % 47) {
        cout<<"GO"<<endl;
    } else {
        cout<<"STAY"<<endl;
    }
}