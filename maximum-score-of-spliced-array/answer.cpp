class Solution {
public:
  int maximumsSplicedArray(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i] + b[i];

    int ans = 0;
    for (int k = 0; k < 2; k++) {
      // not started, swapping, swaped
      vector<int> dp(3, INT_MIN);
      dp[0] = a[0] - b[0];
      dp[1] = b[0] - a[0];

      for (int i = 1; i < n; i++) {
        int x = a[i] - b[i];
        int y = b[i] - a[i];
        vector<int> ndp(3, INT_MIN);

        if (dp[0] != INT_MIN) {
          ndp[0] = max(ndp[0], dp[0] + x);
          ndp[1] = max(ndp[1], dp[0] + y);
        }
        if (dp[1] != INT_MIN) {
          ndp[1] = max(ndp[1], dp[1] + y);
          ndp[2] = max(ndp[2], dp[1] + x);
        }
        if (dp[2] != INT_MIN) {
          ndp[2] = max(ndp[2], dp[2] + x);
        }

        dp = ndp;
      }

      int delta = max(dp[0], dp[2]);
      ans = max(ans, (sum + delta) / 2);

      swap(a, b);
    }
    return ans;
  }
};
