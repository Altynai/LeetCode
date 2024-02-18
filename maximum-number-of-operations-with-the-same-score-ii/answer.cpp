template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxOperations(vector<int> &a) {
    int n = a.size();

    auto Count = [&](int l, int r, int val) -> int {
      if (l >= r)
        return 0;

      vector<vector<int>> dp(n, vector<int>(n, -1));

      function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (i >= j)
          return 0;
        if (dp[i][j] != -1)
          return dp[i][j];

        dp[i][j] = 0;
        if (i + 1 <= j and val == a[i] + a[i + 1])
          umax(dp[i][j], 1 + dfs(i + 2, j));
        if (i + 1 <= j and val == a[j - 1] + a[j])
          umax(dp[i][j], 1 + dfs(i, j - 2));
        if (i + 1 <= j and val == a[i] + a[j])
          umax(dp[i][j], 1 + dfs(i + 1, j - 1));
        return dp[i][j];
      };
      return dfs(l, r);
    };

    int ans = 1 + Count(1, n - 2, a[0] + a[n - 1]);
    umax(ans, 1 + Count(2, n - 1, a[0] + a[1]));
    umax(ans, 1 + Count(0, n - 3, a[n - 2] + a[n - 1]));
    return ans;
  }
};
