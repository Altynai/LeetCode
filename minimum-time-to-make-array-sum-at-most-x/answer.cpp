class Solution {
public:
  int minimumTime(vector<int> &a, vector<int> &b, int x) {
    int n = b.size();
    vector<array<int, 2>> c(n);
    for (int i = 0; i < n; i++)
      c[i] = {b[i], a[i]};

    sort(c.begin(), c.end());
    // maximum reduced value on first i items with j operations
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; i++)
      dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
      auto [added, init] = c[i - 1];
      for (int j = 1; j <= i; j++) {
        // do nothing
        if (dp[i - 1][j] != -1)
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        // use operation
        if (dp[i - 1][j - 1] != -1)
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + init + added * j);
      }
    }

    int suma = accumulate(a.begin(), a.end(), 0);
    int sumb = accumulate(b.begin(), b.end(), 0);
    for (int time = 0; time <= n; time++) {
      int res = suma + sumb * time - dp[n][time];
      if (res <= x)
        return time;
    }
    return -1;
  }
};
