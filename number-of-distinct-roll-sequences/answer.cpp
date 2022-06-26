const int MOD = 1e9 + 7;
const int N = 7;

class Solution {
public:
  int distinctSequences(int n) {
    if (n == 1)
      return 6;

    int dp[N][N] = {0};
    for (int i = 1; i < N; i++) {
      for (int j = 1; j < N; j++) {
        if (i != j and gcd(i, j) == 1)
          dp[i][j]++;
      }
    }

    for (int p = 3; p <= n; p++) {
      int ndp[N][N] = {0};
      for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
          for (int x = 1; x < N; x++) {
            if (x != i and x != j and gcd(j, x) == 1) {
              ndp[j][x] += dp[i][j];
              ndp[j][x] %= MOD;
            }
          }
        }
      }
      copy(&ndp[0][0], &ndp[0][0] + N * N, &dp[0][0]);
    }

    int ans = 0;
    for (int i = 1; i < N; i++) {
      for (int j = 1; j < N; j++) {
        ans += dp[i][j];
        ans %= MOD;
      }
    }
    return ans;
  }
};
