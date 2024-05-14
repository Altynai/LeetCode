const int N = 26;

class Solution {
  bool good(const vector<int> &v) {
    int x = -1;
    for (int i = 0; i < N; i++) {
      if (v[i] == 0)
        continue;
      if (x == -1)
        x = v[i];
      if (v[i] != x)
        return 0;
    }
    return 1;
  }

public:
  int minimumSubstringsInPartition(string s) {
    int n = s.size();
    vector<vector<bool>> balanced(n + 1, vector<bool>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      vector<int> cnt(N, 0);
      for (int j = i; j <= n; j++) {
        cnt[s[j - 1] - 'a']++;
        balanced[i][j] = good(cnt);
      }
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= 1; j--) {
        if (balanced[j][i] and dp[j - 1] != INT_MAX)
          dp[i] = min(dp[i], dp[j - 1] + 1);
      }
    }
    return dp[n];
  }
};
