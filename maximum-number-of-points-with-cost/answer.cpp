// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  long long maxPoints(vector<vector<int>> &p) {
    int n = p.size(), m = p[0].size();
    vector<long long> dp(m, INT_MIN);
    for (int i = 0; i < m; i++) {
      dp[i] = p[0][i];
    }
    for (int i = 1; i < n; i++) {
      vector<long long> ndp(m, INT_MIN);
      long long best = INT_MIN;
      for (int j = 0; j < m; j++) {
        umax(best, dp[j] + j);
        umax(ndp[j], best - j + p[i][j]);
      }
      best = INT_MIN;
      for (int j = m - 1; j >= 0; j--) {
        umax(best, dp[j] - j);
        umax(ndp[j], best + j + p[i][j]);
      }
      dp = ndp;
    }
    return *max_element(dp.begin(), dp.end());
  }
};
