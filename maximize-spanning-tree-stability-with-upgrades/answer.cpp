template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool umin(T &a, const T b) { return a > b ? a = b, 1 : 0; }

struct DSU {
  int n, cnt;
  vector<int> p; // component parent
  vector<int> s; // size

  void init(int _n) {
    cnt = n = _n;
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
    cnt--;
    return 1;
  }

  int components() { return cnt; }

} dsu;

class Solution {
public:
  int maxStability(int n, vector<vector<int>> &edges, int k) {
    sort(edges.begin(), edges.end(),
         [](const auto &lh, const auto &rh) { return lh[2] < rh[2]; });

    vector<vector<int>> musts, optionals;
    for (auto &e : edges) {
      if (e[3] == 1)
        musts.push_back(e);
      else
        optionals.push_back(e);
    }

    auto Test = [&](int val) -> bool {
      dsu.init(n);
      for (auto e : musts) {
        int u = e[0], v = e[1], w = e[2], must = e[3];
        if (w < val)
          return 0;
        if (dsu.same(u, v))
          return 0; // loop
        dsu.join(u, v);
      }
      if (dsu.components() == 1)
        return 1;

      for (auto e : optionals) {
        int u = e[0], v = e[1], w = e[2], must = e[3];
        if (dsu.same(u, v))
          continue;
        if (w < val)
          continue;
        dsu.join(u, v);
      }
      if (dsu.components() == 1)
        return 1;

      int upgrade = 0;
      for (auto e : optionals) {
        int u = e[0], v = e[1], w = e[2], must = e[3];
        if (dsu.same(u, v))
          continue;
        if (w * 2 < val)
          continue;
        dsu.join(u, v);
        upgrade++;
        if (upgrade > k)
          return 0;
      }
      return dsu.components() == 1;
    };

    int ans = -1;
    for (int l = 0, r = 2e5; l <= r;) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};
