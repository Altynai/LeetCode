struct Fenwick {
#define T int

  vector<T> c;
  int n;

  void init(int _n) {
    c.resize(_n + 1);
    n = _n;
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  void add(int x, T y) {
    for (; x <= n; x += x & -x)
      c[x] += y;
  }

  T sum(int x) {
    assert(x <= n);
    T ret = 0;
    for (; x; x -= x & -x)
      ret += c[x];
    return ret;
  }

  int search() {
    int ans = -1;
    for (int l = 1, r = n; l <= r;) {
      int m = (l + r) >> 1;
      if (sum(m) < m) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
} fw;

class Solution {
public:
  vector<int> smallestMissingValueSubtree(vector<int> &p, vector<int> &a) {
    const int maxn = 100001;
    fw.init(maxn);

    int n = p.size();
    vector<vector<int>> g(n);

    int node = -1;
    for (int i = 0; i < n; i++) {
      if (p[i] != -1)
        g[p[i]].push_back(i);
      if (a[i] == 1)
        node = i;
    }

    vector<int> ans(n, 1);
    if (node == -1)
      return ans;

    vector<bool> vis(n, 0);
    function<void(int)> dfs = [&](int u) {
      if (vis[u])
        return;

      vis[u] = 1;
      fw.add(a[u], 1);
      for (int v : g[u])
        dfs(v);
    };

    while (node != -1) {
      dfs(node);
      ans[node] = fw.search();
      node = p[node];
    }
    return ans;
  }
};
