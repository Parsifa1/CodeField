#include <bits/stdc++.h>
using namespace std;
long long a = 0, b = 1, c;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << a << ".00";
    return 0;
}