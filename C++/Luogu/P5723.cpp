#include<bits/stdc++.h>
using namespace std;

int n,t,q,prime[6000010]={0};
bool all[100000010]={0};
int qt[1000001]={0};

int read() {          
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

int main() {
    n=read();
    q=read();
    
    for(int i=2;i<=n;i++) {
        if(all[i]==0) {
            prime[t++]=i;
        }
    
        for(int j=0;j<t&&i*prime[j]<=n;j++) {
            all[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
        
    }
    for(int k=0;k<q;k++) {
        int h;
        h=read();
        printf("%d\n",prime[h-1]);
    }
    return 0;
}
