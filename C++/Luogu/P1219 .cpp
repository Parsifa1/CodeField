#include <bits/stdc++.h>
using namespace std;
bool vis[15],tr1[30],tr2[30];

int n,ans[15],cnt;
void dfs(int x){	//x表示当前行数
	if(x==n+1){
		cnt++;
		if(cnt<=3){
			for(int i=1;i<=n;i++)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){		//枚举当前行的每一列
		if(!vis[i]&&!tr1[x+i]&&!tr2[x-i+n]){ 
			vis[i]=1;tr1[x+i]=1;tr2[x-i+n]=1;
			ans[x]=i;
			dfs(x+1);
			vis[i]=0;tr1[x+i]=0;tr2[x-i+n]=0;
		}
	}
	return;
}
int main() {
	cin>>n;
	dfs(1);
	cout<<cnt<<endl;
	return 0;
}