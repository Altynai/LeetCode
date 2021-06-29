// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  long long maxAlternatingSum(vector<int> &a) {
    int n = a.size();
    vector<vector<long long>> dp(n, vector<long long>(2, LLONG_MIN));
    dp[0][0] = 0;
    dp[0][1] = a[0];

    for (int i = 1; i < n; i++) {
      // do nothing
      umax(dp[i][0], dp[i - 1][0]);
      umax(dp[i][1], dp[i - 1][1]);
      // pick
      umax(dp[i][0], dp[i - 1][1] - a[i]);
      umax(dp[i][1], dp[i - 1][0] + a[i]);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};
