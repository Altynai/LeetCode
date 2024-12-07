template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  int findMinimumTime(vector<int> &strength, int K) {
    // dp[mask][last]: minimum time to break mask locks and
    // tracking the latest broken lock

    int n = strength.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));

    // first lock to break
    for (int i = 0; i < n; i++)
      dp[1 << i][i] = strength[i];

    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if (dp[mask][i] == INT_MAX)
          continue;

        int damage = 1 + bitCount(mask) * K;
        for (int j = 0; j < n; j++) {
          if (bit(mask, j))
            continue;
          umin(dp[mask | (1 << j)][j],
               dp[mask][i] + (strength[j] + damage - 1) / damage);
        }
      }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
      umin(ans, dp[(1 << n) - 1][i]);
    return ans;
  }
};
