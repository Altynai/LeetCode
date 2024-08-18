template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maxEnergyBoost(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<vector<int64>> dp(n, vector<int64>(2, 0));
    dp[0][0] = a[0], dp[0][1] = b[0];
    for (int i = 1; i < n; i++) {
      umax(dp[i][0], dp[i - 1][0] + a[i]);
      umax(dp[i][1], dp[i - 1][1] + b[i]);

      if (i >= 2) {
        umax(dp[i][0], dp[i - 2][1] + a[i]);
        umax(dp[i][1], dp[i - 2][0] + b[i]);
      }
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};
