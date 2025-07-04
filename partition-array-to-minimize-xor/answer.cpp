template <class T> bool umin(T &a, const T b) { return a > b ? a = b, 1 : 0; }

class Solution {
public:
  int minXor(vector<int> &a, int k) {
    // dp[i][j]: answer if can split a[0 .. i] into j groups
    int n = a.size();
    vector<int> pre(n, a[0]);
    for (int i = 1; i < n; i++)
      pre[i] = pre[i - 1] ^ a[i];

    vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
    dp[0][1] = a[0];
    for (int i = 1; i < n; i++) {
      dp[i][1] = pre[i];
      for (int j = 2; j <= k; j++) {
        for (int p = 1; p <= i; p++) {
          if (dp[p - 1][j - 1] == INT_MAX)
            continue;
          // new subarray: a[p ... i]
          int val = pre[i] ^ pre[p - 1];
          umin(dp[i][j], max(dp[p - 1][j - 1], val));
        }
      }
    }
    return dp[n - 1][k];
  }
};
