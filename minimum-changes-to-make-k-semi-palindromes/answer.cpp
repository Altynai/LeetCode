template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minimumChanges(string s, int k) {
    int n = s.size();
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int len = j - i + 1;
        for (int d = 1; d < len; d++) {
          if (len % d != 0)
            continue;

          int total = 0;
          for (int mod = 0; mod < d; mod++) {
            int l = i + mod;
            int r = l + (j - l) / d * d;
            while (l < r) {
              total += int(s[l] != s[r]);
              l += d, r -= d;
            }
          }
          umin(cost[i][j], total);
        }
      }
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i - 1; j >= 1; j--) {
        for (int z = 0; z < k; z++) {
          if (dp[j - 1][z] == INT_MAX)
            continue;
          umin(dp[i][z + 1], dp[j - 1][z] + cost[j - 1][i - 1]);
        }
      }
    }
    return dp[n][k];
  }
};
