const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool between(int l, int x, int r) { return l <= x && x <= r; }
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

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
  vector<int> maxPoints(vector<vector<int>> &a, vector<int> &queries) {
    int n = a.size(), m = a[0].size();
    int k = n * m;

    vector<array<int, 3>> b;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        b.push_back({a[i][j], i, j});
      }
    }
    sort(b.begin(), b.end());

    dsu.init(k);
    map<int, int> cache;
    for (int i = 0; i < k;) {
      int j = i;
      while (j < k and b[j][0] == b[i][0]) {
        int x = b[j][1], y = b[j][2];
        for (int p = 0; p < 4; p++) {
          int nx = x + dx[p], ny = y + dy[p];
          if (inside(n, m, nx, ny) and a[nx][ny] <= a[x][y])
            dsu.join(x * m + y, nx * m + ny);
        }
        j++;
      }

      cache[b[i][0]] = dsu.s[dsu.find(0)];
      i = j;
    }

    vector<int> ans;
    for (int x : queries) {
      int got = 0;
      if (x > a[0][0]) {
        auto it = cache.lower_bound(x);
        if (it != cache.begin())
          got = prev(it)->second;
      }
      ans.push_back(got);
    }
    return ans;
  }
};
