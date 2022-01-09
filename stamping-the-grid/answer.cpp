// 2d BIT 区间增加，单点查询
template <class T> struct Fenwick2D {

  vector<vector<T>> c;
  int n, m;

  Fenwick2D(int _n, int _m) {
    n = _n, m = _m;
    c.resize(_n + 1);
    for (int i = 0; i <= n; i++) {
      c[i].resize(m + 1);
      c[i].assign(m + 1, 0);
    }
  }

  inline int lowbit(int x) { return x & (-x); }

  void add(int x, int y, T val) {
    for (int i = x; i <= n; i += lowbit(i)) {
      for (int j = y; j <= m; j += lowbit(j)) {
        c[i][j] += val;
      }
    }
  }

  void rangeAdd(int x1, int y1, int x2, int y2, T val) {
    add(x1, y1, val);
    add(x1, y2 + 1, -val);
    add(x2 + 1, y1, -val);
    add(x2 + 1, y2 + 1, val);
  }

  // value of (x, y)
  T get(int x, int y) {
    assert(0 <= x && x <= n);
    assert(0 <= y && y <= m);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
      for (int j = y; j > 0; j -= lowbit(j)) {
        ret += c[i][j];
      }
    }
    return ret;
  }
};

class Solution {
public:
  bool possibleToStamp(vector<vector<int>> &a, int h, int w) {
    int n = a.size(), m = a[0].size();

    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
    }

    auto getSum = [&](int r0, int c0, int r1, int c1) -> int {
      r0 += 1, c0 += 1;
      r1 += 1, c1 += 1;
      return sum[r1][c1] - sum[r1][c0 - 1] - sum[r0 - 1][c1] +
             sum[r0 - 1][c0 - 1];
    };

    if (h > n or w > m)
      return getSum(0, 0, n - 1, m - 1) == n * m;

    Fenwick2D<int> bit(n, m);
    for (int i = 0; i + h - 1 < n; i++) {
      for (int j = 0; j + w - 1 < m; j++) {
        if (a[i][j] == 1)
          continue;
        int cnt = getSum(i, j, i + h - 1, j + w - 1);
        if (cnt == 0)
          bit.rangeAdd(i + 1, j + 1, i + h, j + w, 1);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 0 and bit.get(i + 1, j + 1) == 0)
          return false;
      }
    }
    return true;
  }
};
