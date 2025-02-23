template <class T> struct Fenwick {
  vector<T> c;
  int n;

  Fenwick(int _n) {
    n = _n;
    c.resize(_n + 1);
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  inline int lowbit(int x) { return x & (-x); }

  void update(int x, T val) {
    for (int i = x; i <= n; i += lowbit(i))
      c[i] = max(c[i], val);
  }

  T get(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      ret = max(ret, c[i]);
    return ret;
  }
};

const int N = 26;

class Solution {
public:
  bool maxSubstringLength(string s, int k) {
    if (k == 0)
      return 1;

    int n = s.size();
    vector<vector<int>> positions(N);
    for (int i = 0; i < n; i++)
      positions[s[i] - 'a'].push_back(i);

    vector<vector<bool>> must(N, vector<bool>(N, 0));
    for (int i = 0; i < N; i++) {
      if (positions[i].size() == 0)
        continue;
      int l = positions[i][0], r = positions[i].back();
      for (int j = 0; j < N; j++) {
        if (positions[j].size() == 0 or j == i)
          continue;
        auto it = lower_bound(positions[j].begin(), positions[j].end(), l);
        if (it != positions[j].end() and *it < r)
          must[i][j] = 1;
      }
    }

    vector<bool> vis(N, 0);
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      for (int v = 0; v < N; v++) {
        if (must[u][v] and !vis[v])
          dfs(v);
      }
    };

    set<pair<int, int>> ranges;
    for (int i = 0; i < N; i++) {
      if (positions[i].size() == 0)
        continue;
      vis.assign(N, 0);
      dfs(i);
      int l = positions[i][0], r = positions[i].back();
      for (int j = 0; j < N; j++) {
        if (vis[j]) {
          l = min(l, positions[j][0]);
          r = max(r, positions[j].back());
        }
      }
      ranges.insert({l + 1, r + 1});
    }

    vector<pair<int, int>> v(ranges.begin(), ranges.end());
    int m = v.size();
    if (m == 1)
      return 0;

    sort(v.begin(), v.end(),
         [](const auto &lh, const auto &rh) { return lh.second < rh.second; });

    Fenwick<int> bits(n);
    for (int i = 0, j = 0; i < m; i = j) {
      int best = 0;
      while (j < m and v[j].second == v[i].second) {
        auto [l, r] = v[j++];
        best = max(best, bits.get(l - 1) + 1);
      }
      if (best >= k)
        return 1;
      bits.update(v[i].second, best);
    }
    return 0;
  }
};
