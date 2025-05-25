const int N = 26;

class Solution {
public:
  int maxSubstrings(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    vector<vector<int>> pos(N);
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      int x = s[i - 1] - 'a';

      int m = pos[x].size(), k = -1;
      for (int j = m - 1; k == -1 and j >= 0; j--) {
        if (pos[x][j] < i - 2)
          k = pos[x][j];
      }
      if (k != -1)
        dp[i] = max(dp[i], dp[k - 1] + 1);

      pos[x].push_back(i);
    }
    return dp[n];
  }
};
