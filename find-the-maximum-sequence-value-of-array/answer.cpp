const int N = 128;

class Solution {
public:
  int maxValue(vector<int> &a, int k) {
    int n = a.size();

    // forward
    vector<vector<bitset<N>>> dp(n + 1, vector<bitset<N>>(k + 1, 0));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      for (int j = 1; j <= min(i, k); j++) {
        const bitset<N> &b = dp[i - 1][j - 1];
        for (int pos = 0; pos < N; pos++) {
          if (b[pos])
            dp[i][j][pos | a[i - 1]] = 1;
        }
      }
    }

    int ans = 0;

    // backward
    vector<bitset<N>> dp2(k + 1, 0);
    dp2[0][0] = 1;
    for (int i = n; i > k; i--) {
      vector<bitset<N>> ndp2 = dp2;
      for (int j = 1; j <= k; j++) {
        const bitset<N> &b = dp2[j - 1];
        for (int pos = 0; pos < N; pos++) {
          if (b[pos])
            ndp2[j][pos | a[i - 1]] = 1;
        }
      }
      swap(dp2, ndp2);

      const bitset<N> &prefix = dp[i - 1][k];
      for (int x = 0; x < N; x++) {
        if (!prefix[x])
          continue;
        for (int y = 0; y < N; y++) {
          if (!dp2[k][y])
            continue;
          ans = max(ans, x ^ y);
        }
      }
    }

    return ans;
  }
};
