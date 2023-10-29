template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minChanges(string s) {
    int n = s.size();
    vector<vector<int>> dp(2, vector<int>(2, INT_MAX));
    int p = s[0] - '0';
    dp[p][1] = 0;
    dp[p ^ 1][1] = 1;

    for (int i = 1; i < n; i++) {
      vector<vector<int>> ndp(2, vector<int>(2, INT_MAX));
      p = s[i] - '0';
      // keep
      if (dp[p ^ 1][0] != INT_MAX)
        umin(ndp[p][1], dp[p ^ 1][0]);
      if (dp[p][1] != INT_MAX)
        umin(ndp[p][0], dp[p][1]);
      if (dp[p][0] != INT_MAX)
        umin(ndp[p][1], dp[p][0]);
      // change
      if (dp[p ^ 1][1] != INT_MAX)
        umin(ndp[p ^ 1][0], dp[p ^ 1][1] + 1);
      if (dp[p ^ 1][0] != INT_MAX)
        umin(ndp[p ^ 1][1], dp[p ^ 1][0] + 1);
      if (dp[p][0] != INT_MAX)
        umin(ndp[p ^ 1][1], dp[p][0] + 1);

      swap(dp, ndp);
    }
    return min(dp[0][0], dp[1][0]);
  }
};
