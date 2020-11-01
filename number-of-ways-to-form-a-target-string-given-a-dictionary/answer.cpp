class Solution {
public:
  int numWays(vector<string> &words, string t) {
    int n = words.size();
    int m = words[0].size();
    int x = t.size();
    int MOD = 1e9 + 7;

    int cnt[m + 1][26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        cnt[j][words[i - 1][j - 1] - 'a']++;
    }

    int dp[m + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= m; i++)
      dp[i][0] = 1;

    for (int j = 1; j <= x; j++) {
      int idx = t[j - 1] - 'a';
      for (int i = 1; i <= m; i++) {
        dp[i][j] = (1LL * cnt[i][idx] * dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
      }
    }
    return dp[m][x];
  }
};
