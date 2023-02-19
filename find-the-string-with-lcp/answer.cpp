struct DSU {
  int n;
  vector<int> p; // component parent
  vector<int> s; // size

  void init(int _n) {
    n = _n;
    p.resize(n);
    s.resize(n);
    s.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

  bool same(int x, int y) { return find(x) == find(y); }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return 0;

    if (x < y)
      swap(x, y);
    p[y] = x;
    s[x] += s[y];
    return 1;
  }
} dsu;

class Solution {
public:
  string findTheString(vector<vector<int>> &lcp) {
    int n = lcp.size();
    dsu.init(n);

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (lcp[i][j] != lcp[j][i])
          return "";

        int len = lcp[i][j];
        if (len == 0)
          continue;
        if (len > min(n - i, n - j))
          return "";
        if (i + 1 < n and j + 1 < n and lcp[i + 1][j + 1] + 1 != lcp[i][j])
          return "";
        dsu.join(i, j);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (lcp[i][j] == 0 and dsu.same(i, j))
          return "";
      }
    }

    char ch = 'a';
    map<int, char> root;
    string ans(n, '?');
    for (int i = 0; i < n; i++) {
      int r = dsu.find(i);
      if (root.count(r) == 0)
        root[r] = ch++;
      ans[i] = root[r];
    }
    if (root.size() > 26)
      return "";
    return ans;
  }
};
