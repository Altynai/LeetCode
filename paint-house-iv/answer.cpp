template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long minCost(int n, vector<vector<int>> &cost) {
    vector<vector<int64>> dp(3, vector<int64>(3, LLONG_MAX));
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j)
          continue;
        dp[i][j] = cost[0][i] + cost[n - 1][j];
      }
    }

    for (int k = 1; k < n / 2; k++) {
      vector<vector<int64>> ndp(3, vector<int64>(3, LLONG_MAX));
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (i == j)
            continue;

          for (int i2 = 0; i2 < 3; i2++) {
            if (i == i2)
              continue;
            for (int j2 = 0; j2 < 3; j2++) {
              if (i2 == j2 or j == j2)
                continue;
              umin(ndp[i2][j2], dp[i][j] + cost[k][i2] + cost[n - k - 1][j2]);
            }
          }
        }
      }
      swap(dp, ndp);
    }

    int64 ans = LLONG_MAX;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j)
          continue;
        umin(ans, dp[i][j]);
      }
    }
    return ans;
  }
};
