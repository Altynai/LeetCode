template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int paintWalls(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    // choose i paid painters with the mininal cost, sum(time[i] + 1) >= n
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
      vector<int> ndp(n + 1, INT_MAX);
      for (int j = 0; j <= n; j++) {
        if (dp[j] == INT_MAX)
          continue;
        umin(ndp[j], dp[j]);
        int k = min(n, j + time[i] + 1);
        umin(ndp[k], dp[j] + cost[i]);
      }
      swap(dp, ndp);
    }
    return dp[n];
  }
};
