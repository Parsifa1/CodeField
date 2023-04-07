#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
ll a[10010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,mid=1;
        cin >> n;
    
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            if(i!=2)
                mid*=a[i];
        }
        if (mid%a[2] == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
