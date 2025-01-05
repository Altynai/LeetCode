using int64 = long long;

class Solution {
public:
  long long maximumCoins(vector<vector<int>> &c, int k) {
    sort(c.begin(), c.end());
    int n = c.size();
    vector<int64> sum(n);
    for (int i = 0; i < n; i++) {
      sum[i] = 1LL * (c[i][1] - c[i][0] + 1) * c[i][2];
      if (i > 0)
        sum[i] += sum[i - 1];
    }

    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      // fixed left endpoint
      int p = -1, bound = c[i][0] + k - 1;
      for (int l = i, r = n - 1; l <= r;) {
        int mid = (l + r) / 2;
        if (c[mid][0] <= bound)
          p = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      int64 res = sum[p] - (i == 0 ? 0 : sum[i - 1]);
      if (bound < c[p][1])
        res -= 1LL * (c[p][1] - bound) * c[p][2];
      ans = max(ans, res);

      // fixed right endpoint
      p = -1, bound = c[i][1] - k + 1;
      for (int l = 0, r = i; l <= r;) {
        int mid = (l + r) / 2;
        if (c[mid][1] >= bound)
          p = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      res = sum[i] - (p == 0 ? 0 : sum[p - 1]);
      if (bound >= c[p][0])
        res -= 1LL * (bound - c[p][0]) * c[p][2];
      ans = max(ans, res);
    }
    return ans;
  }
};
