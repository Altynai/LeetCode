// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int minSideJumps(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(4, INT_MAX));

    auto isValid = [&](int i, int j) { return a[i] == 0 || a[i] != j; };

    dp[0][2] = 0;
    dp[0][1] = dp[0][3] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= 3; j++) {
        if (dp[i][j] == INT_MAX)
          continue;

        // move forward
        if (isValid(i + 1, j))
          umin(dp[i + 1][j], dp[i][j]);
        // move to another lane
        for (int k = 1; k <= 3; k++) {
          if (j == k || a[i + 1] == k)
            continue;

          // jump at point i
          if (isValid(i, k) && isValid(i + 1, k))
            umin(dp[i + 1][k], dp[i][j] + 1);

          // jump at point i + 1
          if (isValid(i + 1, j) && isValid(i + 1, k))
            umin(dp[i + 1][k], dp[i][j] + 1);
        }
      }
    }

    int ans = INT_MAX;
    for (int j = 1; j <= 3; j++)
      umin(ans, dp[n][j]);
    return ans;
  }
};
