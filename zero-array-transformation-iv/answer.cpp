class Solution {
public:
  int minZeroArray(vector<int> &a, vector<vector<int>> &queries) {
    int mx = *max_element(a.begin(), a.end());
    if (mx == 0)
      return 0;

    int n = a.size(), m = queries.size();

    vector<vector<int>> values(n);
    vector<int> dp(mx + 1, 0), dp2(mx + 1, 0);
    auto Test = [&](int j) -> bool {
      dp.assign(mx + 1, 0);
      dp[0] = 1;
      for (int y : values[j]) {
        copy(dp.begin(), dp.end(), dp2.begin());
        for (int p = y; p <= mx; p++)
          dp2[p] = (dp2[p] || dp[p - y]);
        swap(dp, dp2);
      }
      return dp[a[j]];
    };

    auto TestAll = [&]() -> bool {
      for (int i = 0; i < n; i++) {
        if (!Test(i))
          return 0;
      }
      return 1;
    };

    for (int i = 0; i < m; i++) {
      int l = queries[i][0], r = queries[i][1], v = queries[i][2];
      for (int j = l; j <= r; j++)
        values[j].push_back(v);
      if (TestAll())
        return i + 1;
    }
    return -1;
  }
};
