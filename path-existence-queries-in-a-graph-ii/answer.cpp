#define bit(n, i) (((n) >> (i)) & 1)

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
  vector<int> pathExistenceQueries(int n, vector<int> &a, int maxDiff,
                                   vector<vector<int>> &queries) {

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
      v[i] = {a[i], i};
    sort(v.begin(), v.end());

    // ind[i] = j, original i-th item is at position j now
    vector<int> ind(n);
    for (int i = 0; i < n; i++)
      ind[v[i].second] = i;

    dsu.init(n);
    for (int i = 1; i < n; i++) {
      if (v[i].first - v[i - 1].first <= maxDiff) {
        dsu.join(v[i].second, v[i - 1].second);
      }
    }

    // binary jump table
    const int N = (int)(log(n) / log(2.0)) + 1;
    vector<vector<int>> jump(n, vector<int>(N, -1));
    for (int i = 0; i < n; i++) {
      int j = lower_bound(v.begin(), v.end(),
                          make_pair(v[i].first + maxDiff + 1, 0)) -
              v.begin();
      jump[i][0] = j - 1;
    }
    for (int j = 1; j < N; j++) {
      for (int i = 0; i < n; i++) {
        int k = jump[i][j - 1];
        jump[i][j] = jump[k][j - 1];
      }
    }

    // jump k steps from x to y
    auto Reachable = [&](int x, int y, int k) -> bool {
      for (int i = 0; i < N; i++) {
        if (bit(k, i))
          x = jump[x][i];
        if (x >= y)
          return 1;
      }
      return 0;
    };

    int m = queries.size();
    vector<int> ans(m, 1);
    for (int i = 0; i < m; i++) {
      int u = queries[i][0], v = queries[i][1];
      if (u == v)
        ans[i] = 0;
      else if (!dsu.same(u, v))
        ans[i] = -1;
      else {
        int x = ind[u], y = ind[v];
        if (x > y)
          swap(x, y);
        for (int l = 1, r = n - 1; l <= r;) {
          int mid = (l + r) / 2;
          if (Reachable(x, y, mid))
            ans[i] = mid, r = mid - 1;
          else
            l = mid + 1;
        }
      }
    }
    return ans;
  }
};
