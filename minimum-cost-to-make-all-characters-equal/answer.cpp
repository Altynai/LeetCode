template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
private:
  vector<vector<int64>> calculateDP(const string &s) {
    int n = s.size();
    vector<vector<int64>> dp(n, vector<int64>(2, LLONG_MAX));

    int idx = s[0] - '0';
    dp[0][idx] = 0;
    dp[0][idx ^ 1] = 1;

    for (int i = 1; i < n; i++) {
      idx = s[i] - '0';
      umin(dp[i][idx], dp[i - 1][idx]);
      umin(dp[i][idx], dp[i - 1][idx ^ 1] + i);

      umin(dp[i][idx ^ 1], dp[i - 1][idx] + i + 1);
      umin(dp[i][idx ^ 1], dp[i - 1][idx ^ 1] + i + i + 1);
    }
    return dp;
  }

public:
  long long minimumCost(string s) {
    int n = s.size();
    vector<vector<int64>> f = calculateDP(s);
    reverse(s.begin(), s.end());
    vector<vector<int64>> g = calculateDP(s);

    int64 ans = min(f[n - 1][0], f[n - 1][1]);
    for (int i = 0; i < n; i++) {
      umin(ans, f[i][0] + g[n - 1 - i][0]);
      umin(ans, f[i][1] + g[n - 1 - i][1]);
    }
    return ans;
  }
};
