class Solution {
public:
  int minOperations(string s1, string s2, int x) {
    int n = s1.size();
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i])
        pos.push_back(i);
    }

    int m = pos.size();
    if (m == 0)
      return 0;
    if (m & 1)
      return -1;

    vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
    function<int(int, int)> dfs = [&](int l, int r) -> int {
      if (dp[l][r] != INT_MAX)
        return dp[l][r];
      if (l + 1 == r)
        return dp[l][r] = min(x, pos[r] - pos[l]);

      int best = INT_MAX;
      // pair l and j
      for (int j = l + 1; j <= r; j += 2) {
        int val = min(x, pos[j] - pos[l]);
        if (j >= l + 3)
          val += dfs(l + 1, j - 1);
        if (j + 1 < r)
          val += dfs(j + 1, r);
        best = min(val, best);
      }
      return dp[l][r] = best;
    };
    return dfs(0, m - 1);
  }
};
