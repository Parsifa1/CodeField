#include<iostream>
using namespace std;
int num[1001]={0},add[1001]={0},n;

int main() {
    
    num[0]=1,add[0]=1;
    cin>>n;
    for(int i=2;i<=n;i++) {
        for(int j=0;j<100;j++) {
            num[j]*=i;  
        }
        for(int j=0;j<100;j++) {
            if(num[j]>9) {
                num[j+1]+=num[j]/10;
                num[j]%=10;
            }
        }
        for(int j=0;j<100;j++) {
            add[j]+=num[j];
            if(add[j]>9) {
                add[j+1]+=add[j]/10;
                add[j]%=10;
            }
        }
    }
    int k;
    for(k=100;k>=0;k--) {
        if(add[k]!=0) {
            for(int i=k;i>=0;i--) {
                cout<<add[i];
            }
            return 0;
        }   
    }
    
    
    
}
