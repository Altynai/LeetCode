template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
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

  void update(int x, T val) {
    for (int i = x; i >= 1; i -= lowbit(i))
      c[i] = max(c[i], val);
  }

  // max of [x ... n]
  T get(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i <= n; i += lowbit(i))
      ret = max(ret, c[i]);
    return ret;
  }
};

class Solution {
public:
  vector<int> maximumSumQueries(vector<int> &a, vector<int> &b,
                                vector<vector<int>> &queries) {
    int n = a.size();

    // discrete value for all y
    vector<int> dy = {0};
    for (auto q : queries)
      dy.push_back(q[1]);
    for (int i = 0; i < n; i++)
      dy.push_back(b[i]);
    int m = deduplicate(dy);

    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++)
      c[i] = {a[i], b[i]};
    sort(c.begin(), c.end());

    // sorted queries
    int nq = queries.size();
    vector<array<int, 3>> sq(nq);
    for (int i = 0; i < nq; i++)
      sq[i] = {queries[i][0], queries[i][1], i};
    sort(sq.begin(), sq.end());

    Fenwick<int> bits(m);
    vector<int> ans(nq, -1);
    for (int i = nq - 1, j = n - 1; i >= 0; i--) {
      int yidx = 0;
      while (j >= 0 and c[j].first >= sq[i][0]) {
        yidx = lower_bound(dy.begin(), dy.end(), c[j].second) - dy.begin();
        bits.update(yidx, c[j].first + c[j].second);
        j--;
      }

      yidx = lower_bound(dy.begin(), dy.end(), sq[i][1]) - dy.begin();
      int ret = bits.get(yidx);
      ans[sq[i][2]] = (ret > 0 ? ret : -1);
    }
    return ans;
  }
};
