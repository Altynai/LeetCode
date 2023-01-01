using int64 = long long;

class Solution {
public:
  int minimumPartition(string s, int k) {
    int n = s.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      int64 x = 0, ten = 1;
      for (int j = i; j >= 1; j--, ten *= 10) {
        x += ten * (s[j - 1] - '0');
        if (x > k)
          break;

        if (dp[j - 1] != INT_MAX)
          dp[i] = min(dp[i], dp[j - 1] + 1);
      }
    }
    return (dp[n] == INT_MAX ? -1 : dp[n]);
  }
};
