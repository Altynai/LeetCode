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
  long long makeSubKSumEqual(vector<int> &a, int k) {
    int n = a.size();
    if (n == k)
      return 0;

    dsu.init(n);
    int l = 0, r = k - 1;
    for (int i = 0; i < n; i++) {
      r = (r + 1) % n;
      dsu.join(l, r);
      l = (l + 1) % n;
    }

    unordered_map<int, vector<int>> b;
    for (int i = 0; i < n; i++)
      b[dsu.find(i)].push_back(a[i]);

    long long ans = 0;
    for (auto &[_, v] : b) {
      int m = v.size();
      if (m >= 2) {
        sort(v.begin(), v.end());
        for (int x : v)
          ans += abs(x - v[m / 2]);
      }
    }
    return ans;
  }
};
