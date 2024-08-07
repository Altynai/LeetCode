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
    for (int i = x; i <= n; i += lowbit(i))
      c[i] = c[i] + val;
  }

  // sum of [1 ... x]
  T get(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      ret = ret + c[i];
    return ret;
  }

  T range(int l, int r) { return get(r) - get(l - 1); }
};

class Solution {
public:
  vector<int> numberOfAlternatingGroups(vector<int> &colors,
                                        vector<vector<int>> &queries) {
    int n = colors.size();

    // use 2 fenwick trees to store: total sum of "group size", cnt of specific
    // "group size" for special group crossing n - 1 and 0, we calculate it
    // on-the-fly for operation 1
    set<pair<int, int>> segs;
    Fenwick<int> sum(n), cnt(n);

    auto AddSegment = [&](int l, int r) {
      assert(l <= r);
      int sz = r - l + 1;
      cnt.update(sz, 1), sum.update(sz, sz);
      segs.insert({l, r});
    };

    auto RemoveSegment = [&](int l, int r) {
      auto it = segs.find({l, r});
      assert(it != segs.end());

      int sz = r - l + 1;
      cnt.update(sz, -1), sum.update(sz, -sz);
      segs.erase(it);
    };

    auto FindSegment = [&](int pos) -> pair<int, int> {
      auto it = segs.upper_bound({pos, INT_MAX});
      assert(it != segs.begin());
      return *prev(it);
    };

    // initialize segments
    for (int i = 0; i < n;) {
      if (colors[i] == colors[(i + 1) % n]) {
        AddSegment(i, i);
        i++;
        continue;
      }

      int j = i;
      while (j + 1 < n and colors[j % n] != colors[(j + 1) % n])
        j++;
      AddSegment(i, j);
      i = j + 1;
    }

    int m = queries.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
      int L, R;

      if (queries[i][0] == 1) {
        int sz = queries[i][1];
        int total = sum.range(sz, n);
        int freq = cnt.range(sz, n);
        int res = total - freq * sz + freq;

        // handle the group crossing n - 1 -> 0
        if (colors[0] != colors[n - 1]) {
          tie(L, R) = FindSegment(n - 1);
          int x = R - L + 1;
          tie(L, R) = FindSegment(0);
          int y = R - L + 1;

          if (x == n)
            res += sz - 1; // WTF
          else if (x + y == sz)
            res++;
          else if (x + y > sz) {
            int low = max(1, sz - y);
            int high = min(x, sz - 1);
            res += high - low + 1;
          }
        }
        ans.push_back(res);
      } else {
        int pos = queries[i][1], color = queries[i][2];
        if (colors[pos] == color)
          continue;

        auto [l, r] = FindSegment(pos);

        // case by case, just to be very careful
        if (pos == 0) {

          if (l == r) {
            // 0   0   1   0   1
            // 1   0   1   0   1
            // pos
            RemoveSegment(pos, pos);
            tie(L, R) = FindSegment(pos + 1);
            RemoveSegment(L, R);
            AddSegment(pos, R);
          } else {
            // 1   0   1   0   1
            // 0   0   1   0   1
            // pos
            tie(L, R) = FindSegment(pos + 1);
            RemoveSegment(L, R);
            AddSegment(pos + 1, R);
            AddSegment(pos, pos);
          }
        } else if (pos == n - 1) {
          if (l == r) {
            // 1   0   1   0   0
            // 1   0   1   0   1
            //                pos
            RemoveSegment(pos, pos);
            tie(L, R) = FindSegment(pos - 1);
            RemoveSegment(L, R);
            AddSegment(L, pos);
          } else {
            // 1   0   1   0   1
            // 1   0   1   0   0
            //                pos
            tie(L, R) = FindSegment(pos - 1);
            RemoveSegment(L, R);
            AddSegment(L, pos - 1);
            AddSegment(pos, pos);
          }
        } else {
          // 1   0   0   0   1
          // 1   0   1   0   1
          //        pos
          if (colors[pos - 1] == colors[pos] and
              colors[pos] == colors[pos + 1]) {
            RemoveSegment(pos, pos);
            tie(L, R) = FindSegment(pos - 1);
            RemoveSegment(L, R);
            auto [L2, R2] = FindSegment(pos + 1);
            RemoveSegment(L2, R2);
            AddSegment(L, R2);
          }
          // 0   1   1   0   1
          // 0   1   0   0   1
          //        pos
          else if (colors[pos - 1] == colors[pos] and
                   colors[pos] != colors[pos + 1]) {
            RemoveSegment(l, r);
            tie(L, R) = FindSegment(pos - 1);
            RemoveSegment(L, R);
            AddSegment(L, pos);
            AddSegment(pos + 1, r);
          }
          // 1   0   1   1   0
          // 1   0   0   1   0
          //        pos
          else if (colors[pos - 1] != colors[pos] and
                   colors[pos] == colors[pos + 1]) {
            RemoveSegment(l, r);
            tie(L, R) = FindSegment(pos + 1);
            RemoveSegment(L, R);
            AddSegment(l, pos - 1);
            AddSegment(pos, R);
          }
          // 1   0   1   0   1
          // 1   0   0   0   1
          //        pos
          else {
            RemoveSegment(l, r);
            AddSegment(l, pos - 1);
            AddSegment(pos, pos);
            AddSegment(pos + 1, r);
          }
        }

        colors[pos] = color;
      }
    }
    return ans;
  }
};
