class Solution {
public:
  int minZeroArray(vector<int> &a, vector<vector<int>> &queries) {
    int n = a.size(), m = queries.size();
    vector<int> sum(n, 0);

    int ans = -1;
    for (int l = 0, r = m; l <= r;) {
      int mid = (l + r) / 2;
      sum.assign(n, 0);
      for (int i = 0; i < mid; i++) {
        int x = queries[i][0], y = queries[i][1], val = queries[i][2];
        sum[x] += val;
        if (y + 1 < n)
          sum[y + 1] -= val;
      }

      bool good = 1;
      for (int i = 0; good and i < n; i++) {
        if (i > 0)
          sum[i] += sum[i - 1];
        if (sum[i] < a[i])
          good = 0;
      }

      if (good)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
