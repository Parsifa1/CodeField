#include <iostream>

int main() {
    bool vis[15], tr1[30], tr2[30];
    int n, ans[15], cnt;
    std::cin >> n;

    auto dfs = [&](auto&& self, int x) {
        if (x == n + 1) {
            cnt++;
            if (cnt <= 3) {
                for (int i = 1; i <= n; i++) std::cout << ans[i] << " ";
                std::cout << std::endl;
            }
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && !tr1[x + i] && !tr2[x - i + n]) {
                vis[i] = tr1[x + i] = tr2[x - i + n] = 1;
                ans[x] = i;
                self(self, x + 1);
                vis[i] = tr1[x + i] = tr2[x - i + n] = 0;
            }
        }
    };
    dfs(dfs, 1);
    std::cout << cnt << std::endl;
    return 0;
}
