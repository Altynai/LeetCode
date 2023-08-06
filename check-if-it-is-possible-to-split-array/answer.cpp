class Solution {
public:
  bool canSplitArray(vector<int> &a, int m) {
    int n = a.size();
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + a[i - 1];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (dp[i][j] != -1)
        return dp[i][j];
      if (i == j)
        return dp[i][j] = 1;

      for (int k = i; k < j; k++) {
        // split into [i, k] + [k + 1, j]
        int x = 0;
        if (k == i)
          x = 1;
        else if (sum[k] - sum[i - 1] >= m and dfs(i, k))
          x = 1;

        int y = 0;
        if (k + 1 == j)
          y = 1;
        else if (sum[j] - sum[k] >= m and dfs(k + 1, j))
          y = 1;

        if (x and y)
          return dp[i][j] = 1;
      }
      return dp[i][j] = 0;
    };
    return dfs(1, n);
  }
};
