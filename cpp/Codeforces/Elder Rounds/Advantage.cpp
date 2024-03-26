#include<bits/stdc++.h>
using namespace std;
int num[200010],ans;

int FindArrayMax( int a[], int n ){
	int i;
	int max = 0;
	for (i = 1;i <= n;i++){
		if (a[i] > a[max]){
			max = i;
		}
	}
	return max;
}

void solve() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>num[i];
    }
    int mid=0;
    int maxx =FindArrayMax(num,n);
    for(int j=1;j<=n;j++) {
        if(j!=maxx) {
            cout<<num[j]-num[maxx]<<" ";
        } else {
            mid=num[maxx];
            num[maxx]=0;
            ans=mid-num[FindArrayMax(num,n)];
            num[maxx]=mid;
            cout<<ans<<" ";
        }
    }
    cout<<endl;
}

int main() {
    int T; cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}