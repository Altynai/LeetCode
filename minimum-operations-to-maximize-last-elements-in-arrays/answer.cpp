class Solution {
public:
  int minOperations(vector<int> &a, vector<int> &b) {
    int n = a.size(), ans = INT_MAX;
    for (int i = 0; i < 2; i++) {
      if (i == 1)
        swap(a[n - 1], b[n - 1]);

      vector<int> dp(2, INT_MAX);
      if (a[0] <= a[n - 1] and b[0] <= b[n - 1])
        dp[0] = 0;
      if (b[0] <= a[n - 1] and a[0] <= b[n - 1])
        dp[1] = 1;

      for (int j = 1; j < n - 1; j++) {
        vector<int> ndp(2, INT_MAX);
        for (int k = 0; k < 2; k++) {
          if (dp[k] == INT_MAX)
            continue;
          for (int p = 0; p < 2; p++) {
            int x = (p == 0 ? a[j] : b[j]);
            int y = (p == 0 ? b[j] : a[j]);
            if (x <= a[n - 1] and y <= b[n - 1])
              ndp[p] = min(ndp[p], dp[k] + p);
          }
        }
        swap(dp, ndp);
      }

      int best = min(dp[0], dp[1]);
      if (best != INT_MAX)
        ans = min(ans, best + i);
    }
    if (ans == INT_MAX)
      ans = -1;
    return ans;
  }
};
