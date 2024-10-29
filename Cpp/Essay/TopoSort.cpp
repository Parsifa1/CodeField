#include <iostream>
#include <queue>
#include <set>
#include <vector>

using Graph = std::vector<std::vector<int>>;

const int N = 1e2;
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> in(N);
    std::set<int> vis;
    Graph G(N, std::vector<int>());

    for (int i = 0; i < m; i++) {
        std::vector<int> ans;
        char a, b, g;
        std::cin >> a >> g >> b;
        int u = a - 'A', v = b - 'A';
        G[u].push_back(v);  // 有向图
        in[v]++;            // 入边入度+1
        vis.insert(u), vis.insert(v);
        int res = 0;  // 计数
        auto TopoSort = [&](std::vector<int> in) {
            std::queue<int> q;
            int flag = 0;
            for (auto i : vis)
                if (in[i] == 0) q.push(i);
            if (q.size() > 1) flag = 1;
            while (not q.empty()) {
                auto u = q.front();
                q.pop();
                res++;
                ans.push_back(u);
                for (auto v : G[u]) {
                    if (--in[v] == 0) q.push(v);
                }
                if (q.size() > 1) flag = 1;
            }
            if (ans.size() != vis.size()) {
                return 1;  // 出现环，直接退出
            } else {
                if (flag)
                    return -1;  // 无法确定严格顺序，继续循环
                else
                    return 0;  // 无环且严序
            }
        };

        auto ok = TopoSort(in);
        if (ok == 0 && res == n) {
            std::cout << "Sorted sequence determined after " << i + 1 << " relations: ";
            for (auto x : ans) {
                char c = x + 65;
                std::cout << c;
            }
            std::cout << "." << '\n';
            return 0;
        } else if (ok == -1)
            continue;
        else if (ok == 1) {
            std::cout << "Inconsistency found after " << i + 1 << " relations.";
            return 0;
        }
    }
    std::cout << "Sorted sequence cannot be determined." << '\n';
}
