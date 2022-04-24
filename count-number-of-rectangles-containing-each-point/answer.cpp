template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

template <class T>
vector<int> getOrderedIds(const vector<T> &v, function<bool(int, int)> comp) {
  int n = v.size();
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), comp);
  return p;
}

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

  void add(int x, T val) {
    for (int i = x; i <= n; i += lowbit(i))
      c[i] += val;
  }

  // sum of [1 ... x]
  T sum(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      ret += c[i];
    return ret;
  }
};

class Solution {
public:
  vector<int> countRectangles(vector<vector<int>> &r, vector<vector<int>> &p) {
    int n = r.size(), m = p.size();

    const int N = 101;
    vector<vector<int>> y2x(N);
    vector<int> xs;
    for (int i = 0; i < n; i++) {
      xs.push_back(r[i][0]);
      y2x[r[i][1]].push_back(r[i][0]);
    }
    for (int i = 0; i < m; i++)
      xs.push_back(p[i][0]);

    int nx = deduplicate(xs);
    Fenwick<int> bits(nx);

    auto get_pos = [&](int val) -> int {
      return lower_bound(xs.begin(), xs.end(), val) - xs.begin() + 1;
    };

    vector<int> ids = getOrderedIds(
        p, [&](int x, int y) -> bool { return p[x][1] > p[y][1]; });

    vector<int> ans(m, 0);
    for (int i = 0, y = N - 1; i < m; i++) {
      int k = ids[i];
      while (y >= p[k][1]) {
        for (int x : y2x[y])
          bits.add(get_pos(x), 1);
        y--;
      }
      ans[k] = bits.sum(nx) - bits.sum(get_pos(p[k][0]) - 1);
    }
    return ans;
  }
};
