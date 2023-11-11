const int MOD = 1e9 + 7;

void add(int &x, int y) { x = (x + y % MOD) % MOD; }

class Solution {
public:
  int stringCount(int n) {
    // l, t, e
    int dp[2][2][3] = {0};
    dp[0][0][0] = 23;
    dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = 1;

    for (int i = 2; i <= n; i++) {
      int ndp[2][2][3] = {0};
      for (int l = 0; l < 2; l++) {
        for (int t = 0; t < 2; t++) {
          for (int e = 0; e < 3; e++) {
            // l
            add(ndp[min(l + 1, 1)][t][e], dp[l][t][e]);
            // t
            add(ndp[l][min(t + 1, 1)][e], dp[l][t][e]);
            // e
            add(ndp[l][t][min(e + 1, 2)], dp[l][t][e]);
            // other
            add(ndp[l][t][e], 1LL * dp[l][t][e] * 23 % MOD);
          }
        }
      }

      for (int l = 0; l < 2; l++) {
        for (int t = 0; t < 2; t++) {
          for (int e = 0; e < 3; e++) {
            dp[l][t][e] = ndp[l][t][e];
          }
        }
      }
    }

    return dp[1][1][2];
  }
};
