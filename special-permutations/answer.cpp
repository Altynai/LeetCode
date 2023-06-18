#define bit(n, i) (((n) >> (i)) & 1)

const int MOD = 1e9 + 7;

class Solution {
public:
  int specialPerm(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      dp[1 << i][i] = 1;

    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if (!bit(mask, i))
          continue;

        for (int j = 0; j < n; j++) {
          if (i == j or bit(mask, j))
            continue;
          if (a[i] % a[j] != 0 and a[j] % a[i] != 0)
            continue;
          dp[mask | (1 << j)][j] += dp[mask][i];
          dp[mask | (1 << j)][j] %= MOD;
        }
      }
    }

    int ans = 0, m = (1 << n) - 1;
    for (int i = 0; i < n; i++) {
      ans += dp[m][i];
      ans %= MOD;
    }
    return ans;
  }
};
