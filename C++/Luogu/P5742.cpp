#include <bits/stdc++.h>
using namespace std;
struct student {
   public:
    int num, mark1, mark2;
    double ans;
    bool back() {
        if ((mark1 * 7 + mark2 * 3) >= 800 && mark1 + mark2 > 140)
            return 1;
        else
            return 0;
    }
};  

int main() {
    int n;
    cin >> n;
    student a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].num >> a[i].mark1 >> a[i].mark2;
        a[i].ans = 0.7 * a[i].mark1 + 0.3 * a[i].mark2;
    }
    for (int i = 0; i < n; i++) {
        if (a[i].back())
            cout << "Excellent" << endl;
        else
            cout << "Not excellent" << endl;
    }
    return 0;
}