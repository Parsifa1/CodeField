#include <bits/stdc++.h>
using namespace std;
int num[200001], ans;
bool isrp(int a, int b) {
    if (a == 1 || b == 1)
        return true;
    while (1) {
        int t = a % b;
        if (t == 0)
            break;
        else {
            a = b;
            b = t;
        }
    }
    if (b > 1)
        return false;
    else
        return true;
}
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

int solve() {
    int l;
    cin >> l;
    ans = 0;
    for (int i = 1; i <= l; i++) {
        num[i]=read();
    }

    for (int j = 1; j <= l; j++) {
        for (int i = j; i <= l; i++) {
            if (isrp(num[j], num[i]) == 1) {
                ans = max(ans, (j + i));
            }
        }
    }
    if (ans != 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}