## C++读入优化


```c++	
// 关闭输入输出缓存，使效率提升
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    // 解除cin和cout的默认绑定，来降低IO的负担使效率提升
```

## 二分
### 往左找答案
```c++
while (l < r) {
    int mid = (l + r) >> 1;	//(l+r)/2
    if (check(mid))  r = mid;    // check()判断mid是否满足性质
    else l = mid + 1;
}
```
### 往右找答案
```c++
while (l < r) {
    int mid = (l + r + 1) >> 1;	//(l+r+1)/2
    if (check(mid))  l = mid;
    else r = mid - 1;
}
```

## KMP ：字符串匹配算法


```c++
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

vector<int> find_occurrences(string text, string pattern) {
  string cur = pattern + '#' + text;
  int sz1 = text.size(), sz2 = pattern.size();
  vector<int> v;
  vector<int> lps = prefix_function(cur);
  for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
    if (lps[i] == sz2)
      v.push_back(i - 2 * sz2);
  }
  return v;
}

## 字符串哈希


```c++

ull mod = 1 << 30;
ull hash(std::string s) {
    int res = 1;
    for(int i = 0; i < s.length(); i++) {
        res = ((res * 129 + (ull)s[i]) % mod + mod) % mod;
    }
    return res;
}

```

## 二分图最大匹配 ： 增广路算法（匈牙利算法）

```c++
struct augment_path {
  vector<vector<int> > g;
  vector<int> pa;  // 匹配
  vector<int> pb;
  vector<int> vis;  // 访问
  int n, m;         // 两个点集中的顶点数量
  int dfn;          // 时间戳记
  int res;          // 匹配数

  augment_path(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    vis = vector<int>(n);
    g.resize(n);
    res = 0;
    dfn = 0;
  }

  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }

  bool dfs(int v) {
    vis[v] = dfn;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pb[u] = v;
        pa[v] = u;
        return true;
      }
    }
    for (int u : g[v]) {
      if (vis[pb[u]] != dfn && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }

  int work() {
    while (true) {
      dfn++;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          cnt++;
        }
      }
      if (cnt == 0) {
        break;
      }
      res += cnt;
    }
    return res;
  }
};


```
### 位运算：
#### 异或；
类似于一种不进位加法，特别是多个数之间异或在一起，如果再次对已经在这个集合中的数异或，那么就相当于把这个数从集合中删除了，如果对没有异或过的数异或，那么就相当于把这个数加入到集合中了。
特别的，对于一个数n，n ^ n = 0，n ^ 0 = n。
在二进制数位的观点下看，如果几个数的同一个数位上都是1，那么如果有奇数个1，那么这个数位上的结果就是1，如果有偶数个1，那么这个数位上的结果就是0。
#### 或：
首先，我们要把或运算在二进制的视角下看待,两个数之间的或运算，只会越来越大，因为对于每一个数位，如果有一个数位上是1，那么结果就是1，如果两个数位上都是0，那么结果就是0，也就是说，对于a | b，b的每一个数位在或运算之后要不保持不变，要不从0变成1，从而使得结果变大，所以，如果我们要找到一个数，使得a | x最大，那么我们只需要找到一个数x，使得x的每一个数位都是1，那么a | x就是最大的了。

--2023/9/19
