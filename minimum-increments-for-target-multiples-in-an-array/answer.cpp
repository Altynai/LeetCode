template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

#define bit(n, i) (((n) >> (i)) & 1)

using int64 = long long;

class Solution {

  int64 cost(int64 a, int64 b) {
    if (a % b == 0)
      return 0;
    return (a / b + 1) * b - a;
  };

  int64 dp(const vector<int> &a, const vector<int64> &vals) {
    int n = a.size(), m = vals.size();
    vector<int64> f(1 << m, LLONG_MAX);
    f[0] = 0;

    for (int i = 0; i < n; i++) {
      vector<int64> g = f;
      for (int mask = 0; mask < (1 << m); mask++) {
        if (f[mask] == LLONG_MAX)
          continue;
        for (int j = 0; j < m; j++) {
          if (bit(mask, j) == 0) {
            umin(g[mask | (1 << j)], f[mask] + cost(a[i], vals[j]));
          }
        }
      }
      swap(f, g);
    }
    return f[(1 << m) - 1];
  }

public:
  int minimumIncrements(vector<int> &a, vector<int> &target) {
    int n = a.size();

    int m = target.size();
    vector<vector<int>> groups(m);
    set<vector<int64>> lcms;

    function<void(int)> dfs = [&](int pos) {
      if (pos == m) {
        vector<int64> vals;
        for (int i = 0; i < m; i++) {
          int k = groups[i].size();
          if (k == 0)
            continue;

          int64 val = groups[i][0];
          for (int j = 1; j < k; j++)
            val = lcm(val, groups[i][j]);
          vals.push_back(val);
        }
        sort(vals.begin(), vals.end());
        lcms.insert(vals);
        return;
      }

      for (int gid = 0; gid < m; gid++) {
        groups[gid].push_back(target[pos]);
        dfs(pos + 1);
        groups[gid].pop_back();
      }
    };

    dfs(0);

    int64 ans = LLONG_MAX;
    for (auto vals : lcms)
      umin(ans, dp(a, vals));
    return ans;
  }
};
