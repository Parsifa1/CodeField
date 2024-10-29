#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,k;
int main() {
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++) {
		for(int j=0;j<(1<<n);j++) {
			int ans=i|j;
                if(ans!=(1<<n)-1) {
                    cout<<0<<" ";
                }
                else if(ans==(1<<n)-1) {
                    cout<<1<<" ";
                }
                
            
        }
        printf("\n");
    }
	return 0;
}
