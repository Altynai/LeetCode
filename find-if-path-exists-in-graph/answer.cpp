struct DSU {
  int n;
  vector<int> p;
  vector<int> size;

  void init(int _n) {
    n = _n;
    p.resize(n);
    size.resize(n);
    size.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    int r = x;
    while (p[r] != r)
      r = p[r];
    for (int i = x; p[i] != r;) {
      int j = p[i];
      p[i] = r;
      i = j;
    }
    return r;
  }

  void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      p[y] = x;
      size[x] += size[y];
    }
  }
} dsu;

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
    dsu.init(n);
    for (auto e : edges)
      dsu.join(e[0], e[1]);
    return dsu.find(start) == dsu.find(end);
  }
};
