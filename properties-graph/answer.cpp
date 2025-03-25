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

  int components() {
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(find(i));
    return s.size();
  }

} dsu;

class Solution {
public:
  int numberOfComponents(vector<vector<int>> &p, int k) {
    int n = p.size();

    dsu.init(n);
    for (int i = 0; i < n; i++) {
      set<int> s1(p[i].begin(), p[i].end());
      for (int j = i + 1; j < n; j++) {
        set<int> s2(p[j].begin(), p[j].end());
        int cnt = std::count_if(s1.begin(), s1.end(), [&](int val) {
          return s2.find(val) != s2.end();
        });
        if (cnt >= k)
          dsu.join(i, j);
      }
    }

    return dsu.components();
  }
};
