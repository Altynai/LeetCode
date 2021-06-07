// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int minFlips(string s) {
    auto cal_dp = [&](const string &t) {
      int n = t.size();
      vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
      int p = t[0] - '0';
      dp[0][p] = 0;     // do nothing
      dp[0][p ^ 1] = 1; // type 2

      for (int i = 1; i < n; i++) {
        p = t[i] - '0';
        if (dp[i - 1][p ^ 1] != INT_MAX)
          umin(dp[i][p], dp[i - 1][p ^ 1]);
        if (dp[i - 1][p] != INT_MAX)
          umin(dp[i][p ^ 1], dp[i - 1][p] + 1);
      }
      return dp;
    };

    vector<vector<int>> pfx = cal_dp(s);
    reverse(s.begin(), s.end());
    vector<vector<int>> sfx = cal_dp(s);

    int n = s.size();
    int ans = min(pfx[n - 1][0], pfx[n - 1][1]); // no rotation
    // cout << ans << endl;
    for (int i = 0; i < n - 1; i++) {
      // s[0 .. i][i + 1 .... n - 1]
      // s[i + 1 .... n - 1][0....i]
      // s[j .............0][0....i]
      int j = n - (i + 1) - 1;

      for (int x = 0; x < 2; x++) {
        if (pfx[i][x] == INT_MAX)
          continue;
        int xval = (i & 1 ? x ^ 1 : x);
        for (int y = 0; y < 2; y++) {
          if (sfx[j][y] == INT_MAX)
            continue;
          int yval = (j & 1 ? y ^ 1 : y);
          if (xval != yval)
            umin(ans, pfx[i][x] + sfx[j][y]);
        }
      }
    }
    return ans;
  }
};
