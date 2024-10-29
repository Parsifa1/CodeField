#include <bits/stdc++.h>
int main() {
    std::string s;
    int ans = 0;
    while (std::cin >> s) ans += s.length();
    std::cout << ans << "\n";
    return 0;
}
